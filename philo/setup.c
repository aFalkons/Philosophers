/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/21 07:02:28 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	setup(int ac, char **av, t_philo *ph)
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
	ph->nphilo = ft_atoi(av[0]);
	ph->ttdie = ft_atoi(av[1]);
	ph->tteat = ft_atoi(av[2]);
	ph->ttsleep  = ft_atoi(av[3]);
	if (ac == 5)
		ph->neat = ft_atoi(av[4]);
	else
		ph->neat = -1;
	createlistofph(ph);
}

void	createlistofph(t_philo *ph)
{
	int	i;

	i = 0;
	ph->lphilo = ft_malloc(sizeof(t_listphilo));
	ph->hlphilo = ph->lphilo;
	ph->lphilo->eatcount = 0;
	pthread_mutex_init(&ph->lphilo->fork, NULL);
	ph->lphilo->timevar = 0;
	ph->lphilo->timevar2 = 0;
	ph->lphilo->next = NULL;
	ph->lphilo->philoid = 1;
	while(++i < ph->nphilo)
	{
		ph->lphilo->next = ft_malloc(sizeof(t_listphilo));
		ph->lphilo = ph->lphilo->next;
		ph->lphilo->eatcount = 0;
		ph->lphilo->timevar = 0;
		ph->lphilo->timevar2 = 0;
		ph->lphilo->philoid = i + 1;
		pthread_mutex_init(&ph->lphilo->fork, NULL);
	}
	ph->lphilo->next = ph->hlphilo;
	ph->lphilo = ph->lphilo->next;
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
