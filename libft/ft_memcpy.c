/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 11:32:01 by cjang             #+#    #+#             */
/*   Updated: 2020/12/24 16:52:58 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)dst;
	if (dst == 0 && src == 0)
		return (NULL);
	while (n-- > 0)
		*tmp++ = *(unsigned char *)src++;
	return (dst);
}
