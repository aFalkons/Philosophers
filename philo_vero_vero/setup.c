/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:21:11 by afalconi          #+#    #+#             */
/*   Updated: 2023/07/07 14:41:47 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	setup(int ac, char **av, struct s_singol_philo *ph, int i)
{
	t_philo	*philo_info_test;

	if (ac > 5 || ac < 4)
		ft_exit("Error\n", 1, ph);
	while (++i < ac)
	{
		if (i != 0)
			ckchar(av[i], 0, ph);
		else
			ckchar(av[i], 1, ph);
	}
	philo_info_test = ft_malloc(sizeof(t_philo));
	philo_info_test->n_philo = ft_atoi(av[0]);
	philo_info_test->t_t_die = ft_atoi(av[1]);
	philo_info_test->t_t_eat = ft_atoi(av[2]);
	philo_info_test->t_t_sleep = ft_atoi(av[3]);
	if (ac == 5)
		philo_info_test->n_eat = ft_atoi(av[4]);
	else
		philo_info_test->n_eat = -1;
	pthread_mutex_init(&philo_info_test->print, NULL);
	pthread_mutex_init(&philo_info_test->for_eat, NULL);
	philo_info_test->eat_cont_all_th = 0;
	philo_info_test->isdeat = 0;
	setup2(ph, ft_atoi(av[0]), philo_info_test);
}

void	setup2(struct s_singol_philo *ph, int n, t_philo *philo_info_test)
{
	t_singol_philo	*tmp;
	int				i;

	i = 0;
	ph->philo_id = i + 1;
	pthread_mutex_init(&ph->singol_forks, NULL);
	pthread_mutex_init(&ph->for_death, NULL);
	ph->eat_cont = 0;
	ph->finish_eat = 0;
	ph->finish_eat = 0;
	ph->philo_info = philo_info_test;
	tmp = ph;
	while (++i < n)
	{
		ph->next = ft_malloc(sizeof(t_singol_philo));
		ph = ph->next;
		pthread_mutex_init(&ph->for_death, NULL);
		ph->finish_eat = 0;
		ph->philo_id = i + 1;
		pthread_mutex_init(&ph->singol_forks, NULL);
		ph->eat_cont = 0;
		ph->philo_info = philo_info_test;
	}
	ph->next = tmp;
	ph = ph->next;
}

void	ckchar(char	*av, int f, struct s_singol_philo *ph)
{
	int	i;

	i = -1;
	if (f == 0)
	{
		while (av[++i])
		{
			if (av[i] < 48 || av[i] > 57)
				ft_exit("Error\n", 1, ph);
		}
	}
	else
	{
		while (av[++i])
		{
			if (av[i] < 48 || av[i] > 57)
				ft_exit("Error\n", 1, ph);
			if (i == 0 && av[i] == 48)
				ft_exit("Error\n", 1, ph);
		}
	}
}
