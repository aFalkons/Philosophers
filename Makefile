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

CFILESB =	
OBJ = $(CFILES:.c=.o)

BOBJ = $(CFILESB:.c=.o)

CC = @ gcc
FLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

NAME = philo
NAMEB = philo_bonus

name : $(NAME)

all : $(NAME) $(NAMEB)

$(NAME) : $(OBJ)
	 $(CC) $(FLAGS) $(OBJ) -o $(NAME)

bonus: $(NAMEB)

$(NAMEB) : $(BOBJ)
	 $(CC) $(FLAGS) $(BOBJ) -o $(NAMEB)

clean :
	@ $(RM) $(OBJ)
	@ $(RM) $(BOBJ)

fclean : clean
	@ $(RM) $(NAME)
	@ $(RM) $(NAMEB)

re : fclean all bonus
