NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g3

SRCS =	ft_itoa_base.c \
		ft_printf_utils.c \
		ft_printf.c \
		print_diu.c \
		print_scp.c \
		print_func.c \
		print_x.c \
		printX.c \
		print_percent.c \
		main.c \


all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAGS) -c $(SRCS) -I .
	ar rc $(NAME) $(SRCS:.c=.o) $^
	ranlib $(NAME)

clean:
	rm -rf $(SRCS:.c=.o)
	make clean -C libft 

clean_b:
	rm -rf $(BONUS:.c=.o)

fclean: clean clean_b
	rm -rf $(NAME)
re: fclean all
