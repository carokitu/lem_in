/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgaribot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 13:01:25 by fgaribot          #+#    #+#             */
/*   Updated: 2018/11/14 18:59:22 by fgaribot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*tmp;
	t_list	*first;

	if (!lst)
		return (NULL);
	tmp = (*f)(lst);
	if (!(new_lst = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	first = new_lst;
	lst = lst->next;
	while (lst)
	{
		tmp = (*f)(lst);
		if (!(new_lst->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new_lst = new_lst->next;
		lst = lst->next;
	}
	return (first);
}
