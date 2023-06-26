/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:13:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/26 03:45:59 by afalconi         ###   ########.fr       */
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
		if (singol_philo->philo_info->t_t_die <= gettime() - singol_philo->last_eat)
		{
			pthread_mutex_lock(&singol_philo->philo_info->for_death);
			singol_philo->philo_info->isdeat = 1;
			pthread_mutex_unlock(&singol_philo->philo_info->for_death);
			singol_philo->is_death = 1;
		}
		if (singol_philo->philo_info->isdeat == 1)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
		takeafork(singol_philo);
		if (singol_philo->philo_info->isdeat == 1)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
		if (singol_philo->philo_info->isdeat == 1)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
		xcycle(singol_philo, "is eating\n", singol_philo->philo_info->t_t_eat);
		if (singol_philo->philo_info->isdeat == 1)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
		ck_eat(singol_philo);
		if (singol_philo->philo_info->eat_cont_all_th == singol_philo->philo_info->n_philo)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
		xcycle(singol_philo, "is sleeping\n", singol_philo->philo_info->t_t_sleep);
		if (singol_philo->philo_info->isdeat == 1)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
		ft_stamp(singol_philo, singol_philo->philo_id, "is thinking\n");
		if (singol_philo->philo_info->isdeat == 1)
		{
			if (singol_philo->is_death == 1)
				ft_stamp(singol_philo, singol_philo->philo_id, "died\n");
			break;
		}
	}
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
	ft_stamp(ph, ph->philo_id, str);
	while (ph->timevar2 - ph->timevar <= conditions)
	{
		if (ph->philo_info->isdeat == 1)
			break;
		ph->timevar2 = gettime();
	}
	if (ph->philo_info->isdeat == 1)
			return ;
	printf("gg\n");
	if (str[3] != 'e')
		return ;
	ph->real_fork = 0;
	ph->next->real_fork = 0;
	pthread_mutex_unlock(&ph->singol_forks);
	pthread_mutex_unlock(&ph->next->singol_forks);
	ph->last_eat = ph->timevar2 - ph->timevar;
}

void	ft_stamp(struct s_singol_philo	*ph, int n, char *str)
{
	pthread_mutex_lock(&ph->philo_info->print);
	ph->info_to_stamp = gettime() - ph->start_live;
	printf("%llu %d %s", ph->info_to_stamp, n, str);
	pthread_mutex_unlock(&ph->philo_info->print);
}

void	takeafork(struct s_singol_philo *singol_philo)
{
	while(singol_philo->real_fork == 1)
	{
		if (singol_philo->philo_info->isdeat == 1)
			break;
	}
	if (singol_philo->philo_info->isdeat == 1)
		return;
	pthread_mutex_lock(&singol_philo->singol_forks);
	singol_philo->real_fork = 1;
	ft_stamp(singol_philo, singol_philo->philo_id, "has taken a fork 1\n");
	while(singol_philo->next->real_fork == 1)
	{
		if (singol_philo->philo_info->isdeat == 1)
			break;
	}
	if (singol_philo->philo_info->isdeat == 1)
		return;
	pthread_mutex_lock(&singol_philo->next->singol_forks);
	singol_philo->next->real_fork = 1;
	ft_stamp(singol_philo, singol_philo->philo_id, "has taken a fork 2\n");
}

long int	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	// printf("TIME %ld\n", (tv.tv_usec / 1000) + (tv.tv_sec * 1000));
	// pause();
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}
