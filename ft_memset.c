/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:37:40 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/22 20:13:35 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*strs;

	strs = (char *)str;
	i = 0;
	while (i < n)
	{
		strs[i] = c;
		i++;
	}
	return (strs);
}
