/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfaria-d <pfaria-d@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:41:02 by pfaria-d          #+#    #+#             */
/*   Updated: 2022/11/14 18:49:04 by pfaria-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (0);
	lst2 = ft_lstnew((f)(lst->content));
	if (!lst2)
		return (0);
	tmp = lst2;
	lst = lst->next;
	while (lst)
	{
		lst2->next = ft_lstnew((f)(lst->content));
		if (!lst2->next)
		{
			ft_lstclear(&tmp, del);
			return (0);
		}
		lst2 = lst2->next;
		lst = lst->next;
	}
	return (tmp);
}
