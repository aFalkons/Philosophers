/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:38:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/19 12:56:09 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

// typedef struct s_philo {
// 	t_listphilo		*lphilo;
// 	int				nphilo;
// 	int				neat;
// 	int				ttdie;
// 	int				ttsleep;
// 	int				tteat;
// }	t_philo;

// typedef struct s_listphilo {
// 	pthread_t	*tr;
// 	pthread_mutex_t fork;

// }	t_listphilo;

void*	routine();

#endif
