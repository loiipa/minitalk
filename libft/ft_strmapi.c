/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 17:54:25 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:54:28 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	index;
	unsigned int	len;

	if (!s)
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	newstr = (char *)malloc(len + 1);
	if (!newstr)
		return (NULL);
	while (index < len)
	{
		newstr[index] = f(index, s[index]);
		index++;
	}
	newstr[index] = '\0';
	return (newstr);
}
