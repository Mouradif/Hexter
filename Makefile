# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/29 05:57:20 by mkejji            #+#    #+#              #
#    Updated: 2015/07/29 08:51:16 by mkejji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = src/bsq.c \
	  src/ft_putchar.c \
	  src/ft_putstr.c \
	  src/ft_remap.c \
	  src/ft_test_foreach.c \
	  src/init_grid.c \
	  src/ft_atoi.c \
	  src/ft_putnbr.c \
	  src/ft_realloc.c \
	  src/ft_strlen.c \
	  src/grid.c \
	  src/error_manager.c \
	  src/main.c
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	if [ -a $(NAME) ] ; \
	then \
		rm myApp ; \
	fi;
	gcc $(FLAGS) -Iinclude $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all