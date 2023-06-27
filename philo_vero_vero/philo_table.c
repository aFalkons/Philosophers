/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:13:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/27 14:52:11 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_th_mutex(struct s_singol_philo *ph)
{
	int	i;
	int	n_philo;

	i = -1;
	n_philo = ph->philo_info->n_philo;
	while (++i < n_philo)
	{
		pthread_create(&ph->th_philo, NULL, (void *)philo_routine, ph);
		pthread_detach(ph->th_philo);
		usleep(60);
		ph = ph->next;
	}
}

void	philo_routine(struct s_singol_philo *singol_philo)
{
	singol_philo->start_live = gettime();
	singol_philo->last_eat = singol_philo->start_live;
	while(singol_philo->philo_info->isdeat == 0)
	{
		takeafork(singol_philo);
		xcycle(singol_philo, "is eating\n", singol_philo->philo_info->t_t_eat);
		ck_eat(singol_philo);
		if (singol_philo->philo_info->eat_cont_all_th == singol_philo->philo_info->n_philo)
			break;
		xcycle(singol_philo, "is sleeping\n", singol_philo->philo_info->t_t_sleep);
		ft_stamp(singol_philo, singol_philo->philo_id, "is thinking\n");
	}
	pthread_mutex_lock(&singol_philo->philo_info->for_death);
	singol_philo->philo_info->isdeat ++ ;
	pthread_mutex_unlock(&singol_philo->philo_info->for_death);
}

void	ck_eat(struct s_singol_philo *singol_philo)
{
	if (singol_philo->philo_info->n_eat != -1)
	{
		singol_philo->eat_cont ++;
		if (singol_philo->eat_cont == singol_philo->philo_info->n_eat && singol_philo->finish_eat == 0)
		{
			pthread_mutex_lock(&singol_philo->philo_info->for_eat);
			singol_philo->philo_info->eat_cont_all_th ++;
			pthread_mutex_unlock(&singol_philo->philo_info->for_eat);
			singol_philo->finish_eat = 1;
		}
	}
}

void	xcycle(struct s_singol_philo *ph, char *str, int conditions)
{
	ph->timevar = gettime();
	ph->timevar2 = gettime();
	ck_died(ph);
	ft_stamp(ph, ph->philo_id, str);
	while (ph->timevar2 - ph->timevar <= conditions)
	{
		ph->timevar2 = gettime();
		ck_died(ph);
	}
	ph->last_eat = gettime();
	if (str[3] != 'e')
		return ;
	pthread_mutex_unlock(&ph->singol_forks);
	pthread_mutex_unlock(&ph->next->singol_forks);
}

void	ft_stamp(struct s_singol_philo	*ph, int n, char *str)
{
	pthread_mutex_lock(&ph->philo_info->print);
	ph->info_to_stamp = gettime() - ph->start_live;
	if (ph->philo_info->isdeat == 0 || str[0] == 'd')
		printf("%llu %d %s", ph->info_to_stamp, n, str);
	pthread_mutex_unlock(&ph->philo_info->print);
}

void	takeafork(struct s_singol_philo *singol_philo)
{
	ck_died(singol_philo);
	pthread_mutex_lock(&singol_philo->singol_forks);
	ft_stamp(singol_philo, singol_philo->philo_id, "has taken a fork\n");
	ck_died(singol_philo);
	pthread_mutex_lock(&singol_philo->next->singol_forks);
	ft_stamp(singol_philo, singol_philo->philo_id, "has taken a fork\n");
}

long int	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

void	ck_died(struct s_singol_philo *singol_philo)
{
	if (singol_philo->is_death == 1)
		return ;
	if (gettime() - singol_philo->last_eat >= singol_philo->philo_info->t_t_die)
	{
		pthread_mutex_lock(&singol_philo->philo_info->for_death);
		singol_philo->philo_info->isdeat ++ ;
		pthread_mutex_unlock(&singol_philo->philo_info->for_death);
		singol_philo->is_death = 1;
		pthread_mutex_lock(&singol_philo->philo_info->for_death);
		if (singol_philo->philo_info->isdeat == 0)
			return ;
		pthread_mutex_unlock(&singol_philo->philo_info->for_death);
		ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
	}
}
