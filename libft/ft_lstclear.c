/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 23:03:08 by cjang             #+#    #+#             */
/*   Updated: 2021/01/02 15:26:52 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*first_lst;
	t_list	*second_lst;

	second_lst = *lst;
	*lst = NULL;
	while (second_lst)
	{
		first_lst = second_lst;
		second_lst = second_lst->next;
		del(first_lst->content);
		free(first_lst);
	}
}
