/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:05:28 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:55:40 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	size_t		len;
	char		*cp;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cp = (char *)malloc(len + 1);
	if (!cp)
		return (NULL);
	while (i < len + 1)
	{
		cp[i] = s1[i];
		i++;
	}
	return (cp);
}
