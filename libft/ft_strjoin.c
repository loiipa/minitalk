/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:08:58 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:46:56 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	size_t	len[2];
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len[0] = ft_strlen(s1);
	len[1] = ft_strlen(s2);
	s1s2 = (char *)malloc(len[0] + len[1] + 1);
	if (!s1s2)
		return (NULL);
	while (*s1)
		s1s2[i++] = *s1++;
	while (*s2)
		s1s2[i++] = *s2++;
	s1s2[i] = 0;
	return (s1s2);
}
