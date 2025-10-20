CC = cc
NAME = libftprintf.a
FILES = ft_printf.c ft_functions.c

CFLAGS = -Wall -Wextra -Werror
OBJ = $(FILES:.c=.o)

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
