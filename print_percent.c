/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 21:21:05 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/27 10:48:08 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_precision_percent(t_prtf *structprtf, char wp, char c)
{
	if (wp == 'p')
	{
		while (structprtf->width > 1)
		{
			ft_putprint(c, structprtf);
			structprtf->width--;
		}
	}
	if (wp == 'w')
	{
		while ((structprtf->precision - 1) > 0)
		{
			ft_putprint('0', structprtf);
			structprtf->precision--;
		}
	}
}

static void	ft_minus_percent(t_prtf *structprtf, char p, char c)
{
	ft_putprint(p, structprtf);
	if (structprtf->width > 1)
		ft_width_precision_percent(structprtf, 'p', c);
}

static void	ft_normal_percent(t_prtf *structprtf, char p, char c)
{
	if (structprtf->width > 1)
		ft_width_precision_percent(structprtf, 'p', c);
	ft_putprint(p, structprtf);
}

void		myprint_percent(char p, t_prtf *structprtf)
{
	char	c;

	if (structprtf->zero && !structprtf->precisionfound && !structprtf->minus)
		c = '0';
	else
		c = ' ';
	if (structprtf->minus)
		ft_minus_percent(structprtf, p, c);
	else
		ft_normal_percent(structprtf, p, c);
}
