/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:20:10 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/25 21:20:14 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_precision_p(char *str, t_prtf *structprtf, char wp, char c)
{
	int	len;

	len = ft_strlen(str) + 2;
	if (structprtf->precision > len && structprtf->precisionfound)
		len = structprtf->precision;
	if (wp == 'w')
	{
		if (structprtf->precision < 0)
			structprtf->precision = 0;
		while (structprtf->width > len)
		{
			ft_putprint(c, structprtf);
			structprtf->width--;
		}
	}
	else
	{
		while (structprtf->precision - ft_strlen(str) > 0)
		{
			ft_putprint('0', structprtf);
			structprtf->precision--;
		}
	}
}

void	ft_minus_p(char *str, t_prtf *structprtf, char c)
{
	int	i;

	i = 0;
	structprtf->zero = 0;
	if (structprtf->precisionfound && !structprtf->precision &&
		!str && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	ft_putstr("0x", structprtf);
	ft_putstr(str, structprtf);
	if (structprtf->width >= structprtf->precision + ft_strlen(str) + 2)
		ft_width_precision_p(str, structprtf, 'w', c);
	if (structprtf->precisionfound)
		ft_width_precision_p(str, structprtf, 'p', c);
}

void	ft_normal_p(char *str, t_prtf *structprtf, char c)
{
	int i;

	i = 0;
	if (structprtf->precisionfound && !structprtf->precision &&
		!str && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	if (structprtf->width >= structprtf->precision + ft_strlen(str) + 2)
		ft_width_precision_p(str, structprtf, 'w', c);
	if (structprtf->precisionfound)
		ft_width_precision_p(str, structprtf, 'p', c);
	ft_putstr("0x", structprtf);
	ft_putstr(str, structprtf);
}

void	myprintf_p(va_list *list_printf, t_prtf *structprtf)
{
	void *address;
	char *str;
	char c;

	address = va_arg(*list_printf, void *);
	str = (address == (void *)-1) ? ft_strdup("ffffffffffffffff") :
		ft_itoa_base((intptr_t)address, "0123456789abcdef");
	if (!*str && !structprtf->width)
		return ;
	if (structprtf->precision < 0)
		structprtf->precision = ft_strlen(str);
	if (structprtf->zero && !structprtf->precisionfound && !structprtf->minus)
		c = '0';
	else
		c = ' ';
	if (structprtf->minus && structprtf->width)
		ft_minus_p(str, structprtf, c);
	else
		ft_normal_p(str, structprtf, c);
	free(str);
}
