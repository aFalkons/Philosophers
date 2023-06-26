# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 05:41:09 by afalconi          #+#    #+#              #
#    Updated: 2023/06/24 10:19:46 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES =	philo.c \
			utils.c \
			setup.c \
			philo_table.c
OBJ = $(CFILES:.c=.o)

CC = @ gcc
FLAGS = -pthread -g -Wall -Wextra -Werror
RM = rm -rf

NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
	 $(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	@ $(RM) $(OBJ)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all
