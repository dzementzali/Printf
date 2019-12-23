/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:37:44 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/21 11:00:39 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *x;

	if (!*alst)
		*alst = new;
	x = *alst;
	while (x->next != NULL)
		x = x->next;
	x->next = new;
	new->next = NULL;
}
