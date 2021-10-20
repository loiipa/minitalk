/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 14:07:34 by cjang             #+#    #+#             */
/*   Updated: 2020/12/25 15:30:30 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len > 0)
	{
		if (*haystack == *needle)
		{
			n = 0;
			while (haystack[n] == needle[n] && needle[n] && len > 0)
			{
				n++;
				len--;
			}
			if (!needle[n])
				return ((char *)haystack);
			len += n;
		}
		haystack++;
		len--;
	}
	return (NULL);
}
