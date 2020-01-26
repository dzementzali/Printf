/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:15:25 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/25 21:07:29 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	init_struc(t_prtf *structure)
{
	structure->conv = 0;
	structure->star = 0;
	structure->zero = 0;
	structure->minus = 0;
	structure->width = 0;
	structure->precision = 0;
	structure->precisionfound = 0;
	structure->neg = 0;
	return (1);
}

void	apply_conv(t_prtf *structprtf, va_list *list_printf)
{
	if (structprtf->conv == 's')
		myprintf_s(list_printf, structprtf);
	else if (structprtf->conv == 'c')
		myprintf_c(list_printf, structprtf);
	else if (structprtf->conv == 'p')
		myprintf_p(list_printf, structprtf);
	if (structprtf->conv == 'd' || structprtf->conv == 'i')
		myprintf_di(va_arg(*list_printf, int), structprtf);
	if (structprtf->conv == 'u')
		myprintf_u(list_printf, structprtf);
	if (structprtf->conv == 'X' || structprtf->conv == 'x')
		myprintf_x(list_printf, structprtf);
	else if (structprtf->conv == '%')
		myprint_percent('%', structprtf);
}

int		recup_number(char *str, int *i, t_prtf *structprtf)
{
	int beg;

	while (str[*i] != structprtf->conv && ft_isdigit(str[*i]) != 1)
		*i = *i + 1;
	beg = *i;
	while (ft_isdigit(str[*i]))
		*i = *i + 1;
	*i = *i - 1;
	return (ft_atoi(str + beg));
}

void	check_flag(char *str, t_prtf *structprtf, va_list list_printf)
{
	int i;

	i = structprtf->perc;
	while (str[i] != structprtf->conv)
	{
		while (str[i] == '-')
			check_flag_mod(&i, structprtf, 'm');
		while (str[i] == '0')
			check_flag_mod(&i, structprtf, 'z');
		if (str[i] == '*' && structprtf->precisionfound == 0)
			check_flag_star(&i, structprtf, list_printf);
		if (ft_isdigit(str[i]) == 1 && str[i] != '0' &&
				structprtf->precisionfound == 0)
		{
			structprtf->width = recup_number(str, &i, structprtf);
			i++;
		}
		if (str[i] == '.')
			check_flag_precision(str, &i, structprtf, list_printf);
		else
			return ;
	}
}

int		check_conv(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == 's' || str[*i] == 'd' || str[*i] == 'c' ||
				str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X' ||
				str[*i] == 'i' || str[*i] == '%' || str[*i] == 'p')
			return (1);
		*i = *i + 1;
	}
	return (0);
}
