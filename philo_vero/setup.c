/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 04:41:04 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	setup(int ac, char **av, struct s_philo *ph)
{
	int i;

	i = -1;
	if (ac > 5 || ac < 4)
		ft_exit("Error\n", 1);
	while(++i < ac)
	{
		if (i != 0)
			ckchar(av[i], 0);
		else
			ckchar(av[i], 1);
	}
	ph->n_philo = ft_atoi(av[0]);
	ph->t_t_die = ft_atoi(av[1]);
	ph->t_t_eat = ft_atoi(av[2]);
	ph->t_t_sleep  = ft_atoi(av[3]);
	if (ac == 5)
		ph->n_eat = ft_atoi(av[4]);
	else
		ph->n_eat = -1;
	ph->singol_philo = ft_malloc(ph->n_philo * sizeof(t_singol_philo));

}

void	ckchar(char	*av, int f)
{
	int	i;

	i = -1;
	if (f == 0)
	{
		while(av[++i])
		{
			if (av[i] < 48 || av[i] > 57)
				ft_exit("Error\n", 1);
		}
	}else
	{
		while(av[++i])
		{
			if (av[i] < 48 || av[i] > 57)
				ft_exit("Error\n", 1);
			if (i == 0 && av[i] == 48)
				ft_exit("Error\n", 1);
		}
	}
}
