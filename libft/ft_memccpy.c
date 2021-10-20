/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:32:01 by cjang             #+#    #+#             */
/*   Updated: 2020/12/23 04:50:20 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dst++ = *(unsigned char *)src;
			return (dst);
		}
		*(unsigned char *)dst++ = *(unsigned char *)src++;
		n--;
	}
	return (NULL);
}
