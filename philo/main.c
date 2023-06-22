/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:54:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/22 14:00:21 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	t_philo ph;
	setup(ac - 1, &av[1], &ph);
	// pthread_create(&(ph.lphilo->tr), NULL, (void *)test, NULL);
	// pthread_join(ph.lphilo->tr, NULL);
	while (++i < ph.nphilo / 2)
	{
		printf("GG\n");
		// exephilo(&ph);
		pthread_create(&(ph.lphilo->tr), NULL, (void *)exephilo, &ph);
		usleep(1);
		if (ph.lphilo->next->next != NULL)
			ph.lphilo = ph.lphilo->next->next;
	}
	return(0);
}

	// struct timeval tv;
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
	// while(1)
	// {
	// 	gettimeofday(&tv, NULL);
	// 	printf("%d\n", tv.tv_usec);
	// }





