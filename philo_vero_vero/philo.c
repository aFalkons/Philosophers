/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:51:16 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/04 02:03:08 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	struct s_singol_philo	*ph;

	ph = ft_malloc(sizeof(t_singol_philo));
	setup(ac - 1, &av[1], ph);
	init_th_mutex(ph);
	while (ph->philo_info->isdeat != ph->philo_info->n_philo)
		;
	all_free(ph);
	return (0);
}
