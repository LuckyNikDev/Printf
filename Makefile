NAME = libftprintf.a

LIST = ft_printf.c ft_parser.c utils_printf.c utils_printf2.c utils_printf3.c specifiers_printf.c specifiers_printf2.c engine_printf.c engine_printf2.c

OBJ = $(patsubst %.c, %.o, $(LIST))

HEAD = printf.h

FLAGS = -Wall -Werror -Wextra

all	: $(NAME)

$(NAME)	: $(OBJ) $(HEAD)
	ar rcs $(NAME) $?

%.o	: %.c
	gcc $(FLAGS) -c $< -o $@

clean	:
	rm -f $(OBJ)

fclean	: clean
	rm -f $(NAME)

re	 : fclean all

.PHONY	: all clean fclean re