/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_precision.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:02:01 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/26 01:22:23 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		recup_number_two(char *str, int i, t_prtf *structprtf)
{
	int		beg;

	while (str[i] != structprtf->conv && ft_isdigit(str[i]) != 1)
		i++;
	beg = i;
	while (ft_isdigit(str[i]))
		i++;
	i--;
	return (ft_atoi(str + beg));
}

void			check_flag_precision(char *str, int *i,
			t_prtf *structprtf, va_list list_printf)
{
	structprtf->precisionfound = 1;
	if (str[*i + 1] == '*')
	{
		structprtf->star = 1;
		structprtf->precision = va_arg(list_printf, int);
		*i = *i + 2;
	}
	if (ft_isdigit(str[*i + 1]) && str[*i] != structprtf->conv)
	{
		structprtf->precision = recup_number_two(str, *i, structprtf);
		*i = *i + 1;
	}
	if (str[*i + 1] == structprtf->conv)
		*i = *i + 1;
	else
		return ;
}
