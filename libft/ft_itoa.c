/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 15:16:57 by cjang             #+#    #+#             */
/*   Updated: 2021/07/16 15:56:33 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_len(int n)
{
	int		len;
	int		n_tmp;

	len = 0;
	n_tmp = n;
	while (n_tmp)
	{
		n_tmp /= 10;
		len++;
	}
	if (n == 0)
		return (1);
	else if (n > 0)
		return (len);
	else
		return (len + 1);
}

static int	check_digit(int n)
{
	int		digit;

	digit = 1;
	while (n / 10 >= digit)
		digit *= 10;
	return (digit);
}

static int	check_minus(int n, int *i, char *alp)
{
	alp[*i] = '-';
	*i += 1;
	if (n == -2147483648)
	{
		alp[*i] = '2';
		*i += 1;
		return (147483648);
	}
	return (n * -1);
}

char	*ft_itoa(int n)
{
	int		digit;
	int		i;
	int		len;
	char	*alp;

	i = 0;
	len = check_len(n);
	alp = (char *)malloc(len + 1);
	if (!alp)
		return (NULL);
	if (n < 0)
		n = check_minus(n, &i, alp);
	digit = check_digit(n);
	while (i < len)
	{
		alp[i++] = n / digit + '0';
		n %= digit;
		digit /= 10;
	}
	alp[i] = '\0';
	return (alp);
}
