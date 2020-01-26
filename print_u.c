/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:25:24 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/25 21:29:39 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_unsigned(unsigned int nb)
{
	int count;

	count = 0;
	if (nb < 0)
		count++;
	if (nb == 0)
		count++;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

void	ft_width_precision_u(unsigned int nb, t_prtf *structprtf,
		char wp, char c)
{
	int		len;

	len = ft_count_unsigned(nb);
	if (structprtf->precision > ft_count_unsigned(nb)
	&& structprtf->precisionfound)
		len = structprtf->precision;
	if (wp == 'w')
		while (structprtf->width-- > len)
			ft_putprint(c, structprtf);
	if (wp == 'p')
	{
		len = structprtf->precision;
		while (len-- - ft_count_unsigned(nb) > 0)
			ft_putprint('0', structprtf);
	}
}

void	ft_minus_u(unsigned int nb, t_prtf *structprtf, char c)
{
	structprtf->zero = 0;
	if (structprtf->precisionfound &&
	!structprtf->precision && !nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	if (structprtf->precisionfound)
		ft_width_precision_u(nb, structprtf, 'p', c);
	ft_putnbr_unsigned(nb, structprtf);
	ft_width_precision_u(nb, structprtf, 'w', c);
}

void	ft_normal_u(unsigned int nb, t_prtf *structprtf, char c)
{
	if (structprtf->precisionfound &&
	!structprtf->precision && !nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	ft_width_precision_u(nb, structprtf, 'w', c);
	if (structprtf->precisionfound)
		ft_width_precision_u(nb, structprtf, 'p', c);
	ft_putnbr_unsigned(nb, structprtf);
}

void	myprintf_u(va_list *list_printf, t_prtf *structprtf)
{
	unsigned int	nb;
	char		c;

	nb = va_arg(*list_printf, unsigned int);
	if (structprtf->precisionfound &&
	!structprtf->precision && !nb && !structprtf->width)
		return ;
	c = ' ';
	if (structprtf->zero && !structprtf->minus &&
	(!structprtf->precisionfound || structprtf->precision < 0))
		c = '0';
	if (structprtf->minus)
		ft_minus_u(nb, structprtf, c);
	else
		ft_normal_u(nb, structprtf, c);
}
