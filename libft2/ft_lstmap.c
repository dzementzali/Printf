/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzementz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:49:21 by dzementz          #+#    #+#             */
/*   Updated: 2019/10/21 18:35:25 by dzementz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list *mapi;

	if (!lst || !f)
		return (NULL);
	if (!(mapi = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&mapi, del);
		return (NULL);
	}
	mapi->next = ft_lstmap(lst->next, f, del);
	return (mapi);
}
