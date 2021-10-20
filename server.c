/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 21:56:18 by cjang             #+#    #+#             */
/*   Updated: 2021/07/27 01:00:20 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal			g_sig_s;

static void	re_request_signal(t_signal *sig, int process_id)
{
	sig->bit_index = 0;
	if (sig->handler_flag == 1)
	{
		sig->book_size = 0;
		usleep(USLEEP_TIME);
		kill(process_id, SIGUSR2);
	}
	else if (sig->handler_flag == 2)
	{
		while (sig->word_size-- > 0)
			sig->book[sig->book_index + sig->word_size] = 0;
		sig->book_index = 0;
		sig->word_size = 0;
		usleep(USLEEP_TIME);
		kill(process_id, SIGUSR2);
	}
	else if (sig->handler_flag == 3)
	{
		init_t_signal(sig);
		sig->handler_flag = 1;
		usleep(USLEEP_TIME);
		kill(process_id, SIGUSR2);
	}
}

static void	server_handler(int signo, siginfo_t *siginfo, void *void_arg)
{
	int		flag;

	(void)void_arg;
	flag = g_sig_s.handler_flag;
	if (flag == 0)
		g_sig_s.handler_flag = receive_start(signo, siginfo, &g_sig_s);
	else if (flag == 1)
		g_sig_s.handler_flag = receive_len(signo, siginfo, &g_sig_s);
	else if (flag == 2)
		g_sig_s.handler_flag = receive_data(signo, siginfo, &g_sig_s);
	else if (flag == 3)
		g_sig_s.handler_flag = receive_vefify(signo, siginfo, &g_sig_s);
}

static void	write_pid(void)
{
	int		process_id;

	process_id = getpid();
	ft_putstr_fd("The Server PID is : ", 1);
	ft_putnbr_fd(process_id, 1);
	ft_putendl_fd("", 1);
}

int	main(void)
{
	struct sigaction	act_s;
	int					error_num;

	write_pid();
	init_t_signal(&g_sig_s);
	act_s.sa_flags = SA_SIGINFO;
	sigemptyset(&act_s.sa_mask);
	sigaddset(&act_s.sa_mask, SIGUSR1);
	sigaddset(&act_s.sa_mask, SIGUSR2);
	init_handler(&act_s, server_handler);
	while (TRUE)
	{
		if (g_sig_s.handler_flag == 0)
		{
			error_num = 0;
			if (sleep(600) == 0)
				exit_message("Time over", 1);
		}
		else if (sleep(1) == 0)
		{
			re_request_signal(&g_sig_s, g_sig_s.pid_num);
			if (++error_num == 5)
				exit_message("Server has many signal error.", 1);
		}
	}
}
