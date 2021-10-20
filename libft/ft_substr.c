/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 03:26:17 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:53:55 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	if (s_len <= start)
	{
		*sub = 0;
		return (sub);
	}
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
