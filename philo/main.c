/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:54:04 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 01:04:51 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



int	main(int ac, char **av)
{
	int	i;
	t_listphilo *ph;
	t_philo infoph;

	i = -1;
	setup(ac - 1, &av[1], ph, infoph);
	printf("%d\n", ph->struct_philo->nphilo);
	printf("GG\n");
	while (++i < ph->struct_philo->nphilo)
	{
		// pthread_create(&(ph.tr), NULL, (void *)exephilo, &ph.struct_philo.lphilo);
		// pthread_detach((ph.tr));
		// usleep(100);
		printf("%d\n", ph->philoid);
		ph = ph->next;
	}
	// pthread_mutex_init(&ph.struct_philo.print, NULL);
	// pthread_create(&(ph.tr), NULL, (void *)exephilo, &ph);
	// pthread_detach((ph.tr));
	// ph.struct_philo.isdeat = 0;
	// while (++i < ph.nphilo)
	// {
	// 	pthread_create(&(ph.lphilo->tr), NULL, (void *)exephilo, &ph.lphilo);
	// 	pthread_detach((ph.lphilo->tr));
	// 	ph.lphilo = ph.lphilo->next;
	// 	usleep(100);
	// }
	while (1);
	return(0);
}


	// -fsanitize=thread



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





