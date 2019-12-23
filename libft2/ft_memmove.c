/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:36:50 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/22 23:12:32 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int			i;
	char		*d;
	const char	*s;

	d = (char*)dst;
	s = (const char*)src;
	i = -1;
	if (!dst && !src)
		return (NULL);
	if (len == 0)
		return (d);
	if (d < s)
	{
		while (++i < (int)len)
			d[i] = s[i];
	}
	else
	{
		while (++i < (int)len)
			d[(len - 1) - i] = s[(len - 1) - i];
	}
	return (dst);
}
