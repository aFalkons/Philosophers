/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:54:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/19 13:01:55 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	main(int ac, char **av)
{
	struct timeval tv;
	setup(ac - 1,&av[1]);
	// pthread_t p1, p2, p3, p4;
	// pthread_mutex_init(mutex, NULL);
	// if (pthread_create(&p1, NULL, &routine, NULL) != 0) {
	//     return 1;
	// }
	// if (pthread_join(p1, NULL) != 0) {
	//     return 5;
	// }
	// pthread_mutex_destroy(&mutex);
	// printf("Number of mails: %d\n", mails);
	while(1)
	{
		gettimeofday(&tv, NULL);
		printf("%ld\n", tv.tv_usec);
	}
}

void	setup(int ac, char **av)
{
	int i;

	i = -1;
	while(++i < ac)
	{
		if (i != 5)
			ckchar(&av[i], "a");
		else
			ckchar(&av[i], "0");
	}
	
}

void	ckchar(char	*av, char f)
{
	int	i;

	i = -1;
	while(av[++i])
	{
		if (!(av[i] > 48 && av[i] < 57) || av[i] == f)
			printf("tumaadre\n");
	}
}
