/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 17:06:42 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/25 21:17:35 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_count(long nb)
{
	int	count;

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

static void	ft_width_precision_di(long nb, t_prtf *structprtf, char wp, char c)
{
	int	len;

	len = ft_count(nb);
	if (structprtf->precision > ft_count(nb) && structprtf->precisionfound)
		len = structprtf->precision;
	if (wp == 'w')
		while (structprtf->width-- > len)
			ft_putprint(c, structprtf);
	if (wp == 'p')
	{
		if (structprtf->neg == 1)
			ft_putprint('-', structprtf);
		len = structprtf->precision;
		while (len-- - ft_count(nb) > 0)
			ft_putprint('0', structprtf);
	}
}

static void	ft_minus_di(long nb, t_prtf *structprtf, char c)
{
	structprtf->zero = 0;
	if (structprtf->precisionfound && !structprtf->precision &&
		!nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	else
	{
		if (structprtf->precisionfound)
			ft_width_precision_di(nb, structprtf, 'p', c);
		ft_putnbr(nb, structprtf);
		ft_width_precision_di(nb, structprtf, 'w', c);
	}
}

static void	ft_normal_di(long nb, t_prtf *structprtf, char c)
{
	if (structprtf->precisionfound && !structprtf->precision &&
		!nb && structprtf->width)
	{
		while (structprtf->width--)
			ft_putprint(c, structprtf);
		return ;
	}
	else
	{
		ft_width_precision_di(nb, structprtf, 'w', c);
		if (structprtf->precisionfound)
			ft_width_precision_di(nb, structprtf, 'p', c);
		ft_putnbr(nb, structprtf);
	}
}

void		myprintf_di(long nb, t_prtf *structprtf)
{
	char	c;

	if (structprtf->precisionfound && !structprtf->precision && !nb &&
		!structprtf->width)
		return ;
	c = ' ';
	if (structprtf->zero && !structprtf->minus &&
	(!structprtf->precisionfound || structprtf->precision < 0))
		c = '0';
	if (nb < 0 && ((structprtf->zero && (!structprtf->precisionfound ||
		structprtf->precision < 0)) || (structprtf->precisionfound &&
	structprtf->precision >= ft_count(nb) && structprtf->precision > 0)))
	{
		structprtf->width--;
		nb = nb * -1;
		if (structprtf->precision > ft_count(nb))
			structprtf->neg = 1;
		else
			ft_putprint('-', structprtf);
	}
	if (structprtf->minus)
		ft_minus_di(nb, structprtf, c);
	else
		ft_normal_di(nb, structprtf, c);
}
