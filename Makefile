NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -g3

SRCS =	ft_itoa_base.c \
		ft_printf_utils.c \
		ft_printf.c \
		print_di.c \
		print_u.c \
		print_s.c \
		print_p.c \
		print_c.c \
		print_func.c \
		print_x.c \
		print_percent.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_substr.c \
		ft_putstr.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_memset.c \
		ft_check_flag_mod.c \
		ft_check_flag_precision.c \
		ft_check_flag_star.c \


all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRCS) -I .
	ar rc $(NAME) $(SRCS:.c=.o) $^
	ranlib $(NAME)
	rm -Rf *.o

clean:
	rm -rf $(SRCS:.c=.o)
	
fclean: clean
	rm -rf $(NAME)
re: fclean all
