/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 01:38:31 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/24 00:58:25 by afalconi         ###   ########.fr       */
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
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo {
	pthread_mutex_t	print;
	int				nphilo;
	int				neat;
	int				ttdie;
	int				ttsleep;
	int				tteat;
	int				isdeat;
}	t_philo;

typedef struct s_listphilo {
	pthread_t			tr;
	pthread_mutex_t		fork;
	int					eatcount;
	int					philoid;
	u_int64_t			timevar;
	u_int64_t			timevar2;
	u_int64_t			timealive;
	u_int64_t			startlive;
	u_int64_t			info_to_stamp;
	t_philo				*struct_philo;
	struct s_listphilo *next;
}	t_listphilo;

void			setup(int ac, char **av, t_listphilo *ph);
void			ckchar(char	*av, int f);
void			ft_exit(char *str, int f);
int				ft_strlen(char	*str);
int				ft_atoi(char *str);
void			createlistofph(t_listphilo *ph);
void			*ft_malloc(int bytes);
void			exephilo(t_listphilo *ph);
void			test();
void			ft_stamp(t_listphilo	*ph, int n, char *str);
long int		gettime();
void			takeafork(t_listphilo	*ph);
void			xcycle(t_listphilo *ph, char *str, int conditions);
void			initvaluse(t_listphilo *ph, int i, t_philo *tmp);

#endif
