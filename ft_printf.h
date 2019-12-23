#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include "libft/libft.h"

typedef struct s_prtf
{
	int percent;
	char flag;
	int star;
	int zero;
	int minus;
	int width;
	int precision;
	int precisionfound;
	int len;
	char	*line;
	
} t_prtf;

int ft_printf(char *str, ...);
void myprintf_p(va_list *list_printf, t_prtf *structprtf);
void myprintf_c(va_list *list_printf, t_prtf *structprtf);
void myprintf_s(va_list *list_printf, t_prtf *structprtf);
void myprintf_di(va_list *list_printf, t_prtf *structprtf);
void myprintf_u(va_list *list_printf, t_prtf *structprtf);
void myprintf_x(va_list *list_printf, t_prtf *structprtf);
void myprintf_X(va_list *list_printf, t_prtf *structprtf);
void ft_putchar(char c);
void check_convers(char *str, va_list *list_printf);
int  check_flag(char *str, int *i);
void check_mod(char *str, t_prtf *structprtf, va_list list_printf);
void init_struc(t_prtf *structure);
void apply_mod(t_prtf *structprtf, va_list *list_printf);
void apply_scp(t_prtf *structprtf, va_list *list_printf);
void apply_diu(t_prtf *structprtf, va_list *list_printf);
void apply_xX(t_prtf *structprtf, va_list *list_printf);
void apply_percent(t_prtf *structprtf);
void print_struct(t_prtf	structprtf);
void print_recursiv(char c, int n);
void ft_putnbr_unsigned(unsigned int n);
void ft_putnbr(int nb);
char	*ft_itoa_base(long long int value, int base, int maj);
int ft_count(int nb);


#endif
