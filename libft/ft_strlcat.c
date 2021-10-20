/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:30:05 by cjang             #+#    #+#             */
/*   Updated: 2020/12/25 17:57:34 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	str_len;

	str_len = 0;
	while (src[str_len] != '\0')
		str_len++;
	while (*dst != '\0' && dstsize > 0)
	{
		str_len++;
		dstsize--;
		dst++;
	}
	while (*src != '\0' && dstsize > 1)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (dstsize > 0)
		*dst = '\0';
	return (str_len);
}
