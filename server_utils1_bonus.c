/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:37:28 by cjang             #+#    #+#             */
/*   Updated: 2021/07/27 01:24:45 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	receive_vefify(int signo, siginfo_t *siginfo, t_signal *sig)
{
	if (sig->bit_index < 32)
		init_int_to_bit(&sig->check_num, &sig->bit_index, signo);
	if (sig->bit_index == 32)
	{
		if (check_num_verify(sig) == 0)
		{
			ft_putstr_fd(sig->book, 1);
			init_t_signal(sig);
			usleep(USLEEP_TIME);
			kill(siginfo->si_pid, SIGUSR1);
			return (0);
		}
		else
		{
			init_t_signal(sig);
			usleep(USLEEP_TIME);
			kill(siginfo->si_pid, SIGUSR2);
			return (1);
		}
	}
	return (3);
}

int	receive_data(int signo, siginfo_t *siginfo, t_signal *sig)
{
	int		re_num;

	re_num = 2;
	if (sig->bit_index < 32)
		init_int_to_bit(&sig->book_index, &sig->bit_index, signo);
	else if (sig->bit_index < 64)
		init_int_to_bit(&sig->word_size, &sig->bit_index, signo);
	else if (sig->bit_index < 64 + sig->word_size * 8)
		init_str_to_bit(sig, signo);
	if (sig->bit_index == 64 + sig->word_size * 8)
		re_num = data_branch(sig, siginfo);
	return (re_num);
}

int	receive_len(int signo, siginfo_t *siginfo, t_signal *sig)
{
	if (sig->bit_index < 32)
		init_int_to_bit(&sig->book_size, &sig->bit_index, signo);
	if (sig->bit_index == 32)
	{
		if (sig->book_size <= BUFFER_SIZE)
		{
			sig->bit_index = 0;
			usleep(USLEEP_TIME);
			kill(siginfo->si_pid, SIGUSR1);
			return (2);
		}
		else
		{
			sig->bit_index = 0;
			sig->book_size = 0;
			usleep(USLEEP_TIME);
			kill(siginfo->si_pid, SIGUSR2);
			return (1);
		}
	}
	return (1);
}

int	receive_start(int signo, siginfo_t *siginfo, t_signal *sig)
{
	if (signo == SIGUSR1)
	{
		sig->pid_num = siginfo->si_pid;
		usleep(USLEEP_TIME);
		kill(siginfo->si_pid, SIGUSR1);
		return (1);
	}
	else
	{
		sig->pid_num = 0;
		usleep(USLEEP_TIME);
		kill(siginfo->si_pid, SIGUSR2);
		return (0);
	}
}
