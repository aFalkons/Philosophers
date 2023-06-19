# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afalconi <afalconi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 05:41:09 by afalconi          #+#    #+#              #
#    Updated: 2023/06/19 12:53:22 by afalconi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES =	main.c \

OBJ = $(CFILES:.c=.o)

CC = @ gcc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

NAME = philo

all : $(NAME)

$(NAME) : $(OBJ)
	 $(CC) -pthread $(FLAGS) $(OBJ) -o $(NAME)

clean :
	@ $(RM) $(OBJ)

fclean : clean
	@ $(RM) $(NAME)

re : fclean all
