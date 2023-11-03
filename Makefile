NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf2.c ft_printf3.c 

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $(NAME) $(OBJ)

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
