/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:24:09 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/22 20:05:02 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str2;

	if (!str || !*str || start > ((unsigned int)ft_strlen(str) + 1) || len == 0)
		return (ft_calloc(sizeof(char), 1));
	if (!(str2 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (str[i] && i < (len + start))
	{
		str2[j] = str[i];
		i++;
		j++;
	}
	if (str2)
		str2[j] = '\0';
	return (str2);
}
