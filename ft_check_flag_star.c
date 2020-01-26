/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_star.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:02:43 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/26 01:02:47 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag_star(int *i, t_prtf *structprtf, va_list list_printf)
{
	structprtf->star = 1;
	structprtf->width = (va_arg(list_printf, int));
	if (structprtf->width < 0)
	{
		structprtf->minus = 1;
		structprtf->width = structprtf->width * -1;
	}
	else
		structprtf->width = structprtf->width;
	*i = *i + 1;
}
