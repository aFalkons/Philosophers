/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 03:13:43 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 04:53:37 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_th_mutex(struct s_philo *ph)
{
	int	i;
	t_singol_philo *tmp;

	i = -1;
	pthread_mutex_init(&ph->print, NULL);
	while(++i < ph->n_philo)
	{
		tmp = &ph->singol_philo[i];
		tmp->philo_id = i + 1;
		pthread_mutex_init(&tmp->singol_forks, NULL);
	}
	i = -1;
	while(++i < ph->n_philo)
	{
		tmp = &ph->singol_philo[i];
		tmp->philo_info = ph;
	}
	i = -1;
	while (++i < ph->n_philo)
	{
		tmp = &ph->singol_philo[i];
		pthread_create(&tmp->, NULL, (void *)philo_routine, &ph->singol_philo[i]);
		usleep(10);
	}
}

void	philo_routine(t_singol_philo *singol_philo)
{
	while(singol_philo->philo_info->isdeat == 0)
	{
		takeafork(singol_philo);
		xcycle(ph, "is eating\n", ph->t_t_eat);
		xcycle(ph, "is sleeping\n", ph->t_t_sleep);
		if (ph->n_eat != -1)
			ph->eatcount ++;
		ft_stamp(ph, ph->philoid, "is thinking\n");
	}
}

void	takeafork(t_singol_philo *singol_philo)
{
	pthread_mutex_lock(singol_philo->th_philo;
}
