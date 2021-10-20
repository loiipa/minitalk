/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:27:19 by cjang             #+#    #+#             */
/*   Updated: 2021/07/27 01:24:31 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_data_to_bit(void *type, siginfo_t *siginfo, char *type_name)
{
	int		bit_index;

	bit_index = -1;
	if (ft_strncmp("char", type_name, ft_strlen(type_name)) == 0)
	{
		while (++bit_index < 8)
		{
			usleep(USLEEP_TIME);
			if ((*(char *)type & 1 << bit_index) == 1 << bit_index)
				kill(siginfo->si_pid, SIGUSR1);
			else
				kill(siginfo->si_pid, SIGUSR2);
		}
	}
	else if (ft_strncmp("int", type_name, ft_strlen(type_name)) == 0)
	{
		while (++bit_index < 32)
		{
			usleep(USLEEP_TIME);
			if ((*(int *)type & 1 << bit_index) == 1 << bit_index)
				kill(siginfo->si_pid, SIGUSR1);
			else
				kill(siginfo->si_pid, SIGUSR2);
		}
	}
}

int	send_endsig(siginfo_t *siginfo)
{
	usleep(USLEEP_TIME);
	kill(siginfo->si_pid, SIGUSR2);
	return (5);
}

int	send_verify(siginfo_t *siginfo, t_signal *sig)
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
	send_data_to_bit(&check_num, siginfo, "int");
	return (4);
}

int	send_data(int signo, siginfo_t *siginfo, t_signal *sig)
{
	int		word_index;
	char	*word;

	if (signo == SIGUSR1)
		sig->book_index += sig->word_size;
	send_data_to_bit(&sig->book_index, siginfo, "int");
	if ((sig->book_size - sig->book_index) / FORWARDING_SIZE > 0)
		sig->word_size = FORWARDING_SIZE;
	else
		sig->word_size = sig->book_size - sig->book_index;
	send_data_to_bit(&sig->word_size, siginfo, "int");
	word_index = 0;
	while (word_index < sig->word_size)
	{
		word = &sig->book[sig->book_index + word_index];
		send_data_to_bit(word, siginfo, "char");
		word_index++;
	}
	if (sig->book_index + sig->word_size == sig->book_size)
		return (3);
	else
		return (2);
}

int	send_len(siginfo_t *siginfo, t_signal *sig)
{
	int		word_index;

	if (ft_strlen(sig->write_list) / BUFFER_SIZE > 0)
		sig->book_size = BUFFER_SIZE;
	else
		sig->book_size = ft_strlen(sig->write_list);
	word_index = 0;
	while (word_index < sig->book_size)
	{
		sig->book[word_index] = sig->write_list[word_index];
		word_index++;
	}
	send_data_to_bit(&sig->book_size, siginfo, "int");
	return (1);
}
