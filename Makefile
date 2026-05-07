NAME = libftprintf.a
CC = cc
CFLAGS = -Werror -Wall -Wextra
SOURCES = ft_printf.c ./func/ft_putchar.c ./func/ft_putstr.c \
		  ./func/ft_convert_tohex.c ./func/ft_putnbr.c ./func/ft_putptr.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar -r $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
