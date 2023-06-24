/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philotable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:01:34 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 00:40:21 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exephilo(t_listphilo *ph)
{
	int i = -1;
	ph->timealive = gettime() + ph->struct_philo.ttdie;

	// ph->lphilo->startlive = ph->lphilo->timealive - ph->ttdie;
	ph->startlive = gettime();
	// pthread_mutex_lock(&ph->fork);
	// printf("%d\n", ph->philoid);
	// pthread_mutex_unlock(&ph->fork);
	printf("%d\n", ph->next->philoid);
	printf("diocane2\n");
	while(++i < ph->struct_philo.nphilo)
	{
		printf("diocane2\n");
		printf("%d\n", ph->philoid);
		ph = ph->next;
		printf("diocane\n");
	}
	pause();
	while(ph->struct_philo.isdeat == 0)
	{
		takeafork(ph);
		xcycle(ph, "is eating\n", ph->struct_philo.tteat);
		pthread_mutex_unlock(&ph->fork);
		pthread_mutex_unlock(&ph->next->fork);
		xcycle(ph, "is sleeping\n", ph->struct_philo.ttsleep);
		if (ph->struct_philo.neat != -1)
			ph->eatcount ++;
		ft_stamp(ph, ph->philoid, "is thinking\n");
	}
	printf("fine\n");
}

void	ft_stamp(t_listphilo	*ph, int n, char *str)
{
	pthread_mutex_lock(&ph->struct_philo.print);
	ph->info_to_stamp = gettime() - ph->startlive;
	printf("%llu %d %s", ph->info_to_stamp, n, str);
	pthread_mutex_unlock(&ph->struct_philo.print);
}

void	takeafork(t_listphilo	*ph)
{
	pthread_mutex_lock(&ph->fork);
	ft_stamp(ph, ph->philoid, "taken a fork\n");
	pthread_mutex_lock(&ph->next->fork);
	ft_stamp(ph, ph->philoid, "taken a fork\n");
}

void	xcycle(t_listphilo *ph, char *str, int conditions)
{
	ph->timevar = gettime();
	ph->timevar2 = gettime();
	ft_stamp(ph, ph->philoid, str);
	while (ph->timevar2 - ph->timevar <= conditions * 1000)
		ph->timevar = gettime();
}

long int	gettime(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (-1);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}


void	test()
{
	write(2, "GG\n", 3);
	// exit(1);
}
