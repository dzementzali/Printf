/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:36:08 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/22 22:01:23 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*des;
	char	*sour;
	char	x;

	x = (unsigned char)c;
	des = (char *)dest;
	sour = (char *)src;
	i = 0;
	while (i < n && sour[i] != x)
	{
		des[i] = sour[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		des[i] = sour[i];
		return (des + i + 1);
	}
}
