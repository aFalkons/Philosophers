/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:51:16 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 04:41:36 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	struct s_philo *info_philo;

	info_philo = ft_malloc(sizeof(struct s_philo));
	setup(ac - 1, &av[1], info_philo);
	init_th_mutex(info_philo);
}
