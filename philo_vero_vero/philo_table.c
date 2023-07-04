/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:13:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/04 03:52:36 by afalconi         ###   ########.fr       */
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

void	philo_routine(struct s_singol_philo *ph)
{
	ph->start_live = gettime();
	ph->last_eat = ph->start_live;
	while (ph->philo_info->isdeat == 0)
	{
		takeafork(ph);
		xcycle(ph, "is eating\n", ph->philo_info->t_t_eat);
		ck_eat(ph);
		if (ph->philo_info->eat_cont_all_th == ph->philo_info->n_philo)
			break ;
		xcycle(ph, "is sleeping\n", ph->philo_info->t_t_sleep);
		ft_stamp(ph, ph->philo_id, "is thinking\n");
	}
	pthread_mutex_lock(&ph->philo_info->for_death);
	ph->philo_info->isdeat ++ ;
	pthread_mutex_unlock(&ph->philo_info->for_death);
}

void	ck_eat(struct s_singol_philo *ph)
{
	if (ph->philo_info->n_eat != -1)
	{
		ph->eat_cont ++;
		if (ph->eat_cont == ph->philo_info->n_eat && ph->finish_eat == 0)
		{
			pthread_mutex_lock(&ph->philo_info->for_eat);
			ph->philo_info->eat_cont_all_th ++;
			pthread_mutex_unlock(&ph->philo_info->for_eat);
			ph->finish_eat = 1;
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
		ph->timevar2 = gettime();
		if (ck_died(ph) == 1)
			break ;
	}
	if (str[3] != 'e')
		return ;
	ph->last_eat = gettime();
	ph->next->real_fork = 0;
	ph->real_fork = 0;
	pthread_mutex_unlock(&ph->singol_forks);
	pthread_mutex_unlock(&ph->next->singol_forks);
}

void	ft_stamp(struct s_singol_philo *ph, int n, char *str)
{
	pthread_mutex_lock(&ph->philo_info->print);
	ph->info_to_stamp = gettime() - ph->start_live;
	if (ph->philo_info->isdeat == 0 || str[0] == 'd')
		printf("%llu %d %s", ph->info_to_stamp, n, str);
	pthread_mutex_unlock(&ph->philo_info->print);
}
