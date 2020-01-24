#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_prtf
{
	int percent;
	char conv;
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

void ft_putchar(char c);
void check_convers(char *str, va_list *list_printf);
int  check_conv(char *str, int *i);
void check_flag(char *str, t_prtf *structprtf, va_list list_printf);
void init_struc(t_prtf *structure);
void apply_conv(t_prtf *structprtf, va_list *list_printf);
void apply_scp(t_prtf *structprtf, va_list *list_printf);
void apply_diu(t_prtf *structprtf, va_list *list_printf);
void apply_xX(t_prtf *structprtf, va_list *list_printf);
void myprint_percent(char p, t_prtf *structprtf);
void print_struct(t_prtf structprtf);
void print_recursiv(char c, int n, t_prtf *structprtf);
void ft_putnbr_unsigned(unsigned int n,t_prtf *structprtf);
char	*ft_itoa_base(long nb, char *base);
char	*ft_ptoa_base(long long int value, int base, int maj);
int ft_count(long nb);
void	incr_len(t_prtf *structprtf, int nb);

void 			ft_putnbr(long nb, t_prtf *structprtf);
int				ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strdup(const char *str);
int				ft_strlen(const char *str);
char	*ft_substr(char const *str, unsigned int start, size_t len);
void    *ft_calloc(size_t count, size_t size);
void    ft_bzero(void *str, size_t n);


//Rebuild

int flag_checker(char *str, t_prtf *structprtf, va_list list_printf);
void	ft_putprint(char c, t_prtf *structprtf);
void	ft_width_precision_c(t_prtf *structprtf, char wp, char space);
void	ft_minus_c(t_prtf *structprtf, char c, char space);
void	ft_normal_c(t_prtf *structprtf, char c, char space);
void    ft_putstr(char *str, t_prtf *structprtf);



#endif
