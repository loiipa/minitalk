/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:20:41 by cjang             #+#    #+#             */
/*   Updated: 2021/07/27 00:28:26 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_t_signal(t_signal *sig)
{
	int		i;

	i = 0;
	while (i < BUFFER_SIZE)
		sig->book[i++] = 0;
	sig->book[BUFFER_SIZE] = '\0';
	sig->book_size = 0;
	sig->book_index = 0;
	sig->word_size = 0;
	sig->bit_index = 0;
	sig->check_num = 0;
	sig->handler_flag = 0;
}

void	init_handler(struct sigaction *act, void(*fp))
{
	act->sa_sigaction = fp;
	if (sigaction(SIGUSR1, act, NULL) == -1)
		exit_message("sigaction error.", 1);
	if (sigaction(SIGUSR2, act, NULL) == -1)
		exit_message ("sigaction error.", 1);
}

void	exit_message(char *s, int i)
{
	ft_putendl_fd("", 1);
	ft_putendl_fd(s, 1);
	exit(i);
}
