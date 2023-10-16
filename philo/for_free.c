/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 22:00:59 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/07 04:18:58 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_free(struct s_singol_philo *ph)
{
	int						i;
	int						n_philo;
	struct s_singol_philo	*ph_tmp;

	i = -1;
	n_philo = ph->philo_info->n_philo;
	free(ph->philo_info);
	while (++i < n_philo)
	{
		ph_tmp = ph;
		ph = ph->next;
		free(ph_tmp);
	}
}
