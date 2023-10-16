/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:51:16 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/07 14:40:27 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	struct s_singol_philo	*ph;
	pthread_t				jack_the_ripper;

	ph = ft_malloc(sizeof(t_singol_philo));
	setup(ac - 1, &av[1], ph, -1);
	init_th_mutex(ph);
	pthread_mutex_lock(&ph->philo_info->for_death);
	pthread_mutex_lock(&ph->philo_info->for_eat);
	while (ph->philo_info->isdeat == 0
		&& ph->philo_info->eat_cont_all_th < ph->philo_info->n_philo)
	{
		pthread_mutex_unlock(&ph->philo_info->for_death);
		pthread_mutex_unlock(&ph->philo_info->for_eat);
		pthread_mutex_lock(&ph->philo_info->for_death);
		pthread_mutex_lock(&ph->philo_info->for_eat);
	}
	pthread_mutex_unlock(&ph->philo_info->for_death);
	pthread_mutex_unlock(&ph->philo_info->for_eat);
	usleep(1000);
	all_free(ph);
	return (0);
}
