/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 22:27:49 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:50:21 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*front;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	front = ft_lstnew(f(lst->content));
	if (!front)
		return (NULL);
	lst = lst->next;
	tmp = front;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!tmp->next)
		{
			ft_lstclear(&front, del);
			return (NULL);
		}
		lst = lst->next;
		tmp = tmp->next;
	}
	return (front);
}
