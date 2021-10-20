/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:16:05 by cjang             #+#    #+#             */
/*   Updated: 2021/07/27 00:57:07 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal			g_sig_c;

static void	usleep_and_kill(int signo, siginfo_t *siginfo)
{
	usleep(USLEEP_TIME);
	kill(siginfo->si_pid, signo);
}

static int	set_next_word(siginfo_t *siginfo)
{
	if ((int)ft_strlen(g_sig_c.write_list) > g_sig_c.book_size)
	{
		g_sig_c.write_list += g_sig_c.book_size;
		init_t_signal(&g_sig_c);
		usleep(USLEEP_TIME);
		kill(siginfo->si_pid, SIGUSR1);
	}
	else
	{
		init_t_signal(&g_sig_c);
		exit(0);
	}
	return (0);
}

static void	client_handler(int signo, siginfo_t *siginfo, void *void_arg)
{
	int		flag;

	(void)void_arg;
	flag = g_sig_c.handler_flag;
	if (flag == 0 && signo == SIGUSR2)
		usleep_and_kill(SIGUSR1, siginfo);
	else if ((flag == 0 && signo == SIGUSR1) || (flag == 1 && signo == SIGUSR2) \
	|| (flag == 4 && signo == SIGUSR2))
		g_sig_c.handler_flag = send_len(siginfo, &g_sig_c);
	else if ((flag == 1 && signo == SIGUSR1) || flag == 2 \
	|| (flag == 3 && signo == SIGUSR2))
		g_sig_c.handler_flag = send_data(signo, siginfo, &g_sig_c);
	else if (flag == 3 && signo == SIGUSR1)
		g_sig_c.handler_flag = send_verify(siginfo, &g_sig_c);
	else if (flag == 4 && signo == SIGUSR1)
		g_sig_c.handler_flag = send_endsig(siginfo);
	else if (flag == 5 && signo == SIGUSR1)
		usleep_and_kill(SIGUSR2, siginfo);
	else if (flag == 5 && signo == SIGUSR2)
		g_sig_c.handler_flag = set_next_word(siginfo);
}

static void	defence_define(void)
{
	if (BUFFER_SIZE < FORWARDING_SIZE)
		exit_message("BUFFER_SIZE must be bigger than FORWARDING_SIZE.", 1);
	else if (BUFFER_SIZE < 1)
		exit_message("BUFFER_SIZE is more than 1.", 1);
	else if (FORWARDING_SIZE < 1)
		exit_message("FORWARDING_SIZE is more than 1.", 1);
	else if (USLEEP_TIME < 50)
		exit_message("USLEEP_TIME is more than 50.", 1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	act_c;

	defence_define();
	if (argc == 3)
	{
		init_t_signal(&g_sig_c);
		g_sig_c.pid_num = ft_atoi(argv[1]);
		g_sig_c.write_list = argv[2];
		if (g_sig_c.pid_num < 100 || g_sig_c.pid_num > 99998)
			exit_message("PID is between 100 and 99998.", 1);
		act_c.sa_flags = SA_SIGINFO;
		sigemptyset(&act_c.sa_mask);
		sigaddset(&act_c.sa_mask, SIGUSR1);
		sigaddset(&act_c.sa_mask, SIGUSR2);
		init_handler(&act_c, client_handler);
		kill(g_sig_c.pid_num, SIGUSR1);
		while (TRUE)
		{
			if (sleep(6) == 0)
				exit_message("Time over", 1);
		}
	}
	else
		exit_message("please write [server_PID] [string].", 1);
}
