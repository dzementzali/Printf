/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:52:11 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/25 16:04:04 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(char *str, ...)
{
	t_prtf	structprtf;
	va_list	list_printf;
	int		i;

	structprtf.len = 0;
	va_start(list_printf, str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && init_struc(&structprtf) && (structprtf.perc = ++i))
		{
			if (check_conv(str, &i) == 0)
				return (0);
			else
			{
				structprtf.conv = str[i];
				check_flag(str, &structprtf, list_printf);
				apply_conv(&structprtf, &list_printf);
			}
		}
		else
			ft_putprint(str[i], &structprtf);
	}
	//printf("conv -> %d\n", structprtf.width);
	va_end(list_printf);
	return (structprtf.len);
}
