/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 19:08:38 by cjang             #+#    #+#             */
/*   Updated: 2021/07/26 23:23:01 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	init_int_to_bit(int *cur_i, int *bit_index, int signo)
{
	if (signo == SIGUSR1)
		*cur_i |= 1 << *bit_index % 32;
	*bit_index += 1;
}

void	init_str_to_bit(t_signal *sig, int signo)
{
	int		div;
	int		mod;

	div = (sig->bit_index - 64) / 8;
	mod = (sig->bit_index - 64) % 8;
	if (signo == SIGUSR1)
		sig->book[sig->book_index + div] += 1 << mod;
	sig->bit_index += 1;
}

int	data_branch(t_signal *sig, siginfo_t *siginfo)
{
	sig->bit_index = 0;
	if (sig->book_index + sig->word_size == sig->book_size)
	{
		usleep(USLEEP_TIME);
		kill(siginfo->si_pid, SIGUSR1);
		return (3);
	}
	else if (sig->book_index + sig->word_size < sig->book_size)
	{
		sig->book_index = 0;
		sig->word_size = 0;
		usleep(USLEEP_TIME);
		kill(siginfo->si_pid, SIGUSR1);
		return (2);
	}
	else
	{
		while (sig->word_size-- > 0)
			sig->book[sig->book_index + sig->word_size] = 0;
		sig->book_index = 0;
		sig->word_size = 0;
		usleep(USLEEP_TIME);
		kill(siginfo->si_pid, SIGUSR2);
		return (2);
	}
}

int	check_num_verify(t_signal *sig)
{
	int		word_index;
	int		check_num;

	word_index = 0;
	check_num = 0;
	while (word_index < sig->book_size)
	{
		check_num += sig->book[word_index];
		word_index++;
	}
	if (check_num == sig->check_num)
		return (0);
	else
		return (check_num - sig->check_num);
}
