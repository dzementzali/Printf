/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:04:29 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/26 01:17:23 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef	struct		s_prtf
{
	int		perc;
	char	conv;
	int		star;
	int		zero;
	int		minus;
	int		width;
	int		precision;
	int		precisionfound;
	int		len;
	int		neg;
}					t_prtf;

int					ft_printf(char *str, ...);
void				myprintf_p(va_list *list_printf, t_prtf *structprtf);
void				myprintf_c(va_list *list_printf, t_prtf *structprtf);
void				myprintf_s(va_list *list_printf, t_prtf *structprtf);
void				myprintf_di(long nb, t_prtf *structprtf);
void				myprintf_u(va_list *list_printf, t_prtf *structprtf);
void				myprintf_x(va_list *list_printf, t_prtf *structprtf);
void				myprint_percent(char p, t_prtf *structprtf);

int					check_conv(char *str, int *i);
void				check_flag(char *str, t_prtf *structprtf,
													va_list list_printf);
void				check_flag_precision(char *str, int *i, t_prtf *structprtf,
														va_list list_printf);
void				check_flag_star(int *i, t_prtf *structprtf,
va_list list_printf);
void				check_flag_mod(int *i, t_prtf *structprtf, char mz);
void				apply_conv(t_prtf *structprtf, va_list *list_printf);
void				print_struct(t_prtf structprtf);
int					init_struc(t_prtf *structure);

void				ft_putnbr_unsigned(unsigned int n, t_prtf *structprtf);
char				*ft_itoa_base(unsigned long nb, char *base);
int					ft_count(long nb);
void				ft_putprint(char c, t_prtf *structprtf);
void				ft_putstr(char *str, t_prtf *structprtf);

void				ft_putnbr(long nb, t_prtf *structprtf);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
char				*ft_strdup(const char *str);
int					ft_strlen(const char *str);
char				*ft_substr(char const *str, unsigned int start, size_t len);
void				*ft_calloc(size_t count, size_t size);
void				ft_bzero(void *str, size_t n);
void				*ft_memset(void *str, int c, size_t n);
#endif
