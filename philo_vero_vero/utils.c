/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 16:43:59 by afalconi          #+#    #+#             */
/*   Updated: 2023/06/20 22:43:23 by afalconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(char *str, int f)
{
	if (str != NULL)
		write(1, str, ft_strlen(str));
	// if (ps != NULL)
	// 	ft_free(ps);
	exit(f);
}

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	while(str[i])
		i ++;
	return(0);
}

int	ft_atoi(char *str)
{
	int				seg;
	long long		som;
	int				i;

	seg = 1;
	som = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		seg = ',' - str[i];
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			som = (som * 10) + str[i] - 48;
		else
			break ;
		i++;
	}
	return (som * seg);
}

void	*ft_malloc(int bytes)
{
	void	*var;

	var = malloc(bytes);
	if (!var)
		exit(0);
	return (var);
}
