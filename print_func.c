/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 16:19:38 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/25 21:16:51 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_recursiv(char c, int n, t_prtf *structprtf)
{
	while (n > 0)
	{
		write(1, &c, 1);
		structprtf->len++;
		n--;
	}
}

void	ft_putnbr(long nb, t_prtf *structprtf)
{
	if (nb < 10 && nb >= 0)
		ft_putprint(nb + 48, structprtf);
	else if (nb < 0)
	{
		ft_putprint('-', structprtf);
		ft_putnbr(nb * (-1), structprtf);
	}
	else
	{
		ft_putnbr(nb / 10, structprtf);
		ft_putnbr(nb % 10, structprtf);
	}
}

void	ft_putnbr_unsigned(unsigned int n, t_prtf *structprtf)
{
	if (n < 10 && n >= 0)
		ft_putprint(n + 48, structprtf);
	else
	{
		ft_putnbr(n / 10, structprtf);
		ft_putnbr(n % 10, structprtf);
	}
}

void	print_struct(t_prtf structprtf)
{
	printf("percent -> [%d]\n", structprtf.perc);
	printf("flag -> [%c]\n", structprtf.conv);
	printf("minus -> [%d]\n", structprtf.minus);
	printf("star -> [%d]\n", structprtf.star);
	printf("zero -> [%d]\n", structprtf.zero);
	printf("width -> [%d]\n", structprtf.width);
	printf("precision -> [%d]\n", structprtf.precision);
	printf("len -> [%d]\n", structprtf.len);
	printf("precisionfound -> [%d]\n", structprtf.precisionfound);
}

void	ft_putprint(char c, t_prtf *structprtf)
{
	write(1, &c, 1);
	structprtf->len++;
}
