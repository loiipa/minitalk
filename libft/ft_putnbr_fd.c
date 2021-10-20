/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 19:26:52 by cjang             #+#    #+#             */
/*   Updated: 2020/12/29 19:32:33 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		digit;
	char	c;

	digit = 1;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	while (n / 10 >= digit)
		digit *= 10;
	while (digit > 0)
	{
		c = n / digit + '0';
		write(fd, &c, 1);
		n %= digit;
		digit /= 10;
	}
}
