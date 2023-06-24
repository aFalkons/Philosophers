/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 10:53:08 by afalconi         ###   ########.fr       */
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
	pthread_mutex_init(&ph->print, NULL);
	setup2(ph);
}

void	setup2(struct s_philo *ph)
{
	t_singol_philo	*tmp;
	int				i;

	i = -1;
	while(++i < ph->n_philo)
	{
		tmp = &ph->singol_philo[i];
		tmp->philo_id = i + 1;
		pthread_mutex_init(&tmp->singol_forks, NULL);
		tmp->philo_info = ph;
		tmp->f_eatcount = 0;
		if (i != ph->n_philo - 1)
			tmp->next = &ph->singol_philo[i + 1];
		else
			tmp->next = &ph->singol_philo[0];
	}
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
