/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:13:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 11:12:38 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_th_mutex(struct s_philo *ph)
{
	int	i;
	t_singol_philo *tmp;

	i = -1;
	while (++i < ph->n_philo)
	{
		tmp = &ph->singol_philo[i];
		pthread_create(&tmp->th_philo, NULL, (void *)philo_routine, &ph->singol_philo[i]);
		pthread_detach(tmp->th_philo);
		usleep(10);
	}
}

void	philo_routine(t_singol_philo *singol_philo)
{
	singol_philo->start_live = gettime();
	while(singol_philo->philo_info->isdeat == 0)
	{
		if (singol_philo->philo_info->n_eat != -1)
		{
			if(singol_philo->eatcount == singol_philo->philo_info->n_eat)
				break;
		}
		takeafork(singol_philo);
		singol_philo->eatcount ++;
		xcycle(singol_philo, "is eating\n", singol_philo->philo_info->t_t_eat);
		pthread_mutex_unlock(&singol_philo->singol_forks);
		pthread_mutex_unlock(&singol_philo->next->singol_forks);
		xcycle(singol_philo, "is sleeping\n", singol_philo->philo_info->t_t_sleep);
		ft_stamp(singol_philo, singol_philo->philo_id, "is thinking\n");
	}
}

void	xcycle(t_singol_philo *ph, char *str, int conditions)
{
	ph->timevar = gettime();
	ph->timevar2 = gettime();
	ft_stamp(ph, ph->philo_id, str);
	while (ph->timevar2 - ph->timevar <= conditions * 1000)
		ph->timevar = gettime();
}

void	ft_stamp(t_singol_philo	*ph, int n, char *str)
{
	pthread_mutex_lock(&ph->philo_info->print);
	ph->info_to_stamp = gettime() - ph->start_live;
	printf("%llu %d %s", ph->info_to_stamp, n, str);
	pthread_mutex_unlock(&ph->philo_info->print);
}

void	takeafork(t_singol_philo *singol_philo)
{
	pthread_mutex_lock(&singol_philo->singol_forks);
	ft_stamp(singol_philo, singol_philo->philo_id, "has taken a fork\n");
	if(singol_philo->philo_id != singol_philo->philo_info->n_philo)
	pthread_mutex_lock(&singol_philo->next->singol_forks);
	ft_stamp(singol_philo, singol_philo->philo_id, "has taken a fork\n");
}

long int	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
