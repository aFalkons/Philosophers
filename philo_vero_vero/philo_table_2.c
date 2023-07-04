/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:21:50 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/04 03:27:12 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takeafork(struct s_singol_philo *ph)
{
	ph->timevar = gettime();
	while(ph->real_fork == 1)
	{
		ph->timevar2 = gettime();
		if (ph->timevar2 - ph->timevar >= ph->philo_info->t_t_die)
		{
			if (ck_died(ph) == 1)
				break;
		}
	}
	pthread_mutex_lock(&ph->singol_forks);
	ph->real_fork = 1;
	ft_stamp(ph, ph->philo_id, "has taken a fork\n");
	ph->timevar = gettime();
	while(ph->next->real_fork == 1)
	{
		ph->timevar2 = gettime();
		if (ph->timevar2 - ph->timevar >= ph->philo_info->t_t_die)
		{
			if (ck_died(ph) == 1)
				break;
		}
	}
	pthread_mutex_lock(&ph->next->singol_forks);
	ph->next->real_fork = 1;
	ft_stamp(ph, ph->philo_id, "has taken a fork\n");
}

long int	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_usec / 1000) + (tv.tv_sec * 1000));
}

int	ck_died(struct s_singol_philo *ph)
{
	if (ph->is_death == 1)
		return (1);
	if (gettime() - ph->last_eat >= ph->philo_info->t_t_die)
	{
		pthread_mutex_lock(&ph->philo_info->for_death);
		if (ph->philo_info->isdeat == 0)
		{
			ph->philo_info->isdeat ++ ;
			ft_stamp(ph, ph->philo_id, "died\n");
		}
		pthread_mutex_unlock(&ph->philo_info->for_death);
		ph->is_death = 1;
	}
	return (0);
}
