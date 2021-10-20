/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 20:04:52 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:55:13 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			n;

	n = count * size;
	mem = malloc(n);
	if (!mem)
		return (NULL);
	while (n > 0)
		mem[--n] = 0;
	return (mem);
}
