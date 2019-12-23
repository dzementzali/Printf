/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 22:14:59 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/24 10:15:23 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		strverif(const char c, const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != c)
			i++;
		else
			return (1);
	}
	return (0);
}

char			*ft_strtrim(char const *str, char const *set)
{
	int		i;
	int		j;
	int		x;
	char	*s;

	if (!str)
		return (NULL);
	if (set == 0)
		return (ft_calloc(sizeof(char), 1));
	i = 0;
	j = ft_strlen(str) - 1;
	while (strverif(str[i], set) == 1)
		i++;
	if (i == (int)ft_strlen(str))
		return (ft_calloc(sizeof(char), 1));
	while (strverif(str[j], set) == 1)
		j--;
	if (!(s = (char *)malloc(sizeof(char) * ((j + 1) - i) + 1)))
		return (NULL);
	x = 0;
	while (i <= j)
		s[x++] = str[i++];
	s[x] = '\0';
	return (s);
}
