SRC =	src/ft_putchar.c \
	src/ft_putstr.c \
	src/ft_putnbr.c \
	src/ft_strlen.c \

FLAGS = -Wall -Wextra -Werror

NAME = brain

all: $(NAME)

$(NAME): $(SRC)
	gcc $(FLAGS) -Iinclude $(SRC) -o $(NAME) src/main.c

clean:
	rm -f $(NAME)

re: clean all
