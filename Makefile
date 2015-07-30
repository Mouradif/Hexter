# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/29 05:57:20 by mkejji            #+#    #+#              #
#    Updated: 2015/07/30 17:19:20 by mkejji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
SRC = src/bsq.c \
	  src/ft_putchar.c \
	  src/ft_putstr.c \
	  src/ft_atoi.c \
	  src/ft_putnbr.c \
	  src/ft_realloc.c \
	  src/ft_strlen.c \
	  src/grid.c \
	  src/error_manager.c \
	  src/main.c \
	  src/print_grid.c \
	  src/ft_allowed_chars.c \
	  src/ft_set_params.c \
	  src/read_first_line.c \
	  src/init_grid.c \
	  src/ft_getline.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FLAGS) -Iinclude $(SRC) -o $(NAME)

debug: $(SRC)
	gcc $(FLAGS) -g -Iinclude $(SRC) -o $(NAME)-debug

test: $(SRC)
	gcc $(FLAGS) -Iinclude $(SRC) src/test.c -o $(NAME)-test

clean:
	rm -f $(NAME)

re: clean all
