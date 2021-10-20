/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 19:05:54 by cjang             #+#    #+#             */
/*   Updated: 2020/12/24 16:06:19 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_1;
	unsigned char	*tmp_2;

	tmp_1 = (unsigned char *)dst;
	tmp_2 = (unsigned char *)src;
	if (dst > src)
		while (len-- > 0)
			tmp_1[len] = tmp_2[len];
	else if (dst < src)
		while (len-- > 0)
			*tmp_1++ = *tmp_2++;
	return (dst);
}
