# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 05:41:09 by afalconi          #+#    #+#              #
#    Updated: 2023/07/04 00:36:16 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES =	philo.c \
			utils.c \
			setup.c \
			philo_table.c \
			for_free.c \
			philo_table_2.c
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
