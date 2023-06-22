/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philotable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 23:01:34 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/22 14:03:07 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exephilo(t_philo *ph)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	ph->lphilo->timealive = tv.tv_usec;
	ph->lphilo->timevar = tv.tv_usec;
	pthread_mutex_lock(&ph->print);
	printf("%d %d is thinking\n", ph->lphilo->timealive - ph->lphilo->timevar, ph->lphilo->philoid);
	pthread_mutex_unlock(&ph->print);
	pthread_mutex_lock(&ph->hlphilo->fork);
	gettimeofday(&tv, NULL);
	ph->lphilo->timealive = tv.tv_usec;
	pthread_mutex_lock(&ph->print);
	printf("%d %d taken a fork\n", ph->lphilo->timealive - ph->lphilo->timevar, ph->lphilo->philoid);
	pthread_mutex_unlock(&ph->print);
	pthread_mutex_lock(&ph->hlphilo->next->fork);
	gettimeofday(&tv, NULL);
	ph->lphilo->timealive = tv.tv_usec;
	pthread_mutex_lock(&ph->print);
	printf("%d %d taken a fork\n", ph->lphilo->timealive - ph->lphilo->timevar, ph->lphilo->philoid);
	pthread_mutex_unlock(&ph->print);
	gettimeofday(&tv, NULL);
	ph->lphilo->timealive = tv.tv_usec;
	pthread_mutex_lock(&ph->print);
	printf("%d %d is eating\n", ph->lphilo->timealive - ph->lphilo->timevar, ph->lphilo->philoid);
	pthread_mutex_unlock(&ph->print);
	ph->lphilo->timevar = tv.tv_usec;
	ph->lphilo->timevar2 = tv.tv_usec;
	while (ph->lphilo->timevar2 <= ph->lphilo->timevar + ph->tteat * 1000)
	{
		gettimeofday(&tv, NULL);
		ph->lphilo->timevar2 = tv.tv_usec;
		ph->lphilo->timealive = tv.tv_usec;
	}
	pthread_mutex_unlock(&ph->hlphilo->fork);
	pthread_mutex_unlock(&ph->hlphilo->next->fork);
	gettimeofday(&tv, NULL);
	ph->lphilo->timevar = tv.tv_usec;
	ph->lphilo->timevar2 = tv.tv_usec;
	pthread_mutex_lock(&ph->print);
	printf("%d %d is sleeping\n", ph->lphilo->timealive - ph->lphilo->timevar, ph->lphilo->philoid);
	pthread_mutex_unlock(&ph->print);
	while (ph->lphilo->timevar2 <= ph->lphilo->timevar + ph->ttsleep * 1000)
	{
		gettimeofday(&tv, NULL);
		ph->lphilo->timevar2 = tv.tv_usec;
		ph->lphilo->timealive = tv.tv_usec;
	}
	if (ph->neat != -1)
		ph->lphilo->eatcount ++;
}

void	test()
{
	write(2, "GG\n", 3);
	// exit(1);
}
