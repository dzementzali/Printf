/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 01:01:20 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/26 01:01:23 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag_mod(int *i, t_prtf *structprtf, char mz)
{
	if (mz == 'm')
	{
		structprtf->minus = 1;
		*i = *i + 1;
	}
	else
	{
		structprtf->zero = 1;
		*i = *i + 1;
	}
}
