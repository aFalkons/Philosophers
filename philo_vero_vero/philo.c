/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 02:51:16 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/26 03:45:23 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	struct s_singol_philo *ph;
	int i = -1;

	ph = ft_malloc(sizeof(t_singol_philo));
	setup(ac - 1, &av[1], ph);
	init_th_mutex(ph);
	// while(1)
	// {
	// 	if (condiscion_for_end(info_philo) == 1)
	// 		break;
	// }
	sleep(2);
	// while (1);
}

// int condiscion_for_end(struct s_philo *info_philo)
// {
// 	int i;
// 	struct s_singol_philo *tmp;
// 	t_singol_philo *tmp2;

// 	i = 0;
// 	tmp2 = &info_philo->singol_philo[0];
// 	tmp = tmp2->next;
// 	while(tmp->next)
// 	{
// 		printf("%d\n", tmp->philo_id);
// 		// if ()
// 		tmp = tmp->next;
// 	}
// }
