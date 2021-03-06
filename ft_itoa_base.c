/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:51:14 by dzementz          #+#    #+#             */
/*   Updated: 2020/01/27 10:49:03 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(unsigned long nb, int len_base)
{
	int count;

	count = 0;
	while (nb)
	{
		nb = nb / len_base;
		count++;
	}
	return (count);
}

static char		*ft_divmod(unsigned long nb, char *base, int len_base)
{
	char	*res;
	int		len;
	int		mod;

	len = ft_len(nb, len_base);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[len] = '\0';
	len--;
	mod = 0;
	while (nb)
	{
		mod = nb % len_base;
		res[len] = base[mod];
		nb = nb / len_base;
		len--;
	}
	return (res);
}

static char		*ft_nbzer(char *base)
{
	char *res;

	if (!(res = malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = base[0];
	res[1] = 0;
	return (res);
}

char			*ft_itoa_base(unsigned long nb, char *base)
{
	int		len_base;

	len_base = ft_strlen(base);
	if (nb == 0)
		return (ft_nbzer(base));
	if (base == NULL)
		return (NULL);
	return (ft_divmod(nb, base, len_base));
}
