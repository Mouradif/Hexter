# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/29 05:57:20 by mkejji            #+#    #+#              #
#    Updated: 2015/09/12 17:39:36 by jlawson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := bsq

SRC := \
      bsq \
      grid \
      error_manager \
      print_grid \
      ft_allowed_chars \
      ft_set_params \
      read_first_line \
      init_grid \
      draw_square \
      find_max \
      test_full \
      ft_atoi \
      ft_putnbr \
      ft_realloc \
      ft_strlen \
      ft_putchar \
      ft_putstr \
      ft_min \
      ft_getline \
      ft_str

CFLAGS := -Wall -Werror -Wextra -Iinclude
VPATH := src

ifneq ($(VISUAL),y)
	Q = @
endif

ifneq ($(MAIN_TEST),)
	CFLAGS += -g
	NAME := $(join $(NAME),-test)
	DEBUG_OBJ := $(notdir $(addsuffix .o, $(basename $(MAIN_TEST))))

$(DEBUG_OBJ): $(MAIN_TEST)
	$(Q)$(CC) $(CFLAGS) -c $< -o $@
	@echo " CC $@"
else
	CFLAGS += -O2
	SRC += main
endif

OBJ := $(addsuffix .o, $(SRC))

%.o: $(addprefix src/, %.c)
	$(Q)$(CC) $(CFLAGS) -c $< -o $@
	@echo " CC $@"

default: all

all: $(NAME)

$(NAME): $(OBJ) $(DEBUG_OBJ)
	$(Q)$(CC) $(OBJ) $(DEBUG_OBJ) -o $@
	@echo " LD $@"

clean:
	$(Q)$(RM) $(OBJ) $(DEBUG_OBJ)
	@echo " CLEAN $(OBJ)"

fclean: clean
	$(Q)$(RM) $(NAME)
	@echo " FCLEAN $(NAME)"

re: fclean
	$(MAKE) all

.PHONY: all $(NAME) clean fclean re
