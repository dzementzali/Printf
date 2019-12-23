/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:11:36 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/12 21:42:58 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>

int		ft_count(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	char	*itwa;
	int		count;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	count = ft_count(nb);
	if (!(itwa = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	itwa[count] = '\0';
	if (nb <= 0)
	{
		nb = nb * -1;
		itwa[0] = '-';
	}
	count = count - 1;
	while (nb > 0)
	{
		itwa[count] = (nb % 10) + 48;
		nb = nb / 10;
		count--;
	}
	return (itwa);
}
