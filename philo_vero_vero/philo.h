/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:38:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/27 13:52:06 by afalconi         ###   ########.fr       */
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
#include <sys/time.h>

typedef struct s_philo {
	pthread_mutex_t	print;
	int				n_philo;
	int				n_eat;
	int				eat_cont_all_th;
	pthread_mutex_t	for_eat;
	pthread_mutex_t	for_death;
	int				t_t_die;
	int				t_t_sleep;
	int				t_t_eat;
	int				isdeat;
}	t_philo;

typedef struct s_singol_philo {
	u_int64_t		philo_id;
	u_int64_t		eat_cont;
	pthread_t		th_philo;
	pthread_mutex_t	singol_forks;
	u_int64_t				real_fork;
	t_philo			*philo_info;
	u_int64_t		info_to_stamp;
	u_int64_t		start_live;
	u_int64_t		timevar2;
	u_int64_t		timevar;
	u_int64_t		finish_eat;
	u_int64_t		is_death;
	u_int64_t		last_eat;
	u_int64_t		ck_for_death;
	struct s_singol_philo	*next;
}	t_singol_philo;

void		setup(int ac, char **av, struct s_singol_philo *ph);
void		ckchar(char	*av, int f);
void		ft_exit(char *str, int f);
int			ft_strlen(char	*str);
int			ft_atoi(char *str);
void		*ft_malloc(int bytes);
void		init_th_mutex(struct s_singol_philo *ph);
void		setup2(struct s_singol_philo *ph, int nuber_of_node, t_philo	*philo_info);
long int	gettime(void);
void		xcycle(struct s_singol_philo *ph, char *str, int conditions);
void		ft_stamp(struct s_singol_philo	*ph, int n, char *str);
void		takeafork(struct s_singol_philo *singol_philo);
void		philo_routine(struct s_singol_philo *singol_philo);
int			condiscion_for_end(struct s_philo *info_philo);
void		ck_eat(struct s_singol_philo *singol_philo);
void		ck_died(struct s_singol_philo *singol_philo);


#endif
