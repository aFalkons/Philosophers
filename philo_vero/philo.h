/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:38:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 04:53:05 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_singol_philo {
	int				philo_id;
	int				eat_cont;
	pthread_t		th_philo;
	pthread_mutex_t	singol_forks;
	struct s_philo	*philo_info;
}	t_singol_philo;


typedef struct s_philo {
	pthread_mutex_t	print;
	int				n_philo;
	int				n_eat;
	int				t_t_die;
	int				t_t_sleep;
	int				t_t_eat;
	int				isdeat;
	t_singol_philo	*singol_philo;
}	t_philo;

void			setup(int ac, char **av, t_philo *ph);
void			ckchar(char	*av, int f);
void			ft_exit(char *str, int f);
int				ft_strlen(char	*str);
int				ft_atoi(char *str);
void			*ft_malloc(int bytes);
void			init_th_mutex(t_philo *ph);

#endif
