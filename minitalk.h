/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:03:33 by cjang             #+#    #+#             */
/*   Updated: 2021/07/27 01:01:38 by cjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FORWARDING_SIZE
#  define FORWARDING_SIZE 128
# endif

# ifndef USLEEP_TIME
#  define USLEEP_TIME 100
# endif

typedef struct s_signal_info
{
	char				*write_list;
	int					pid_num;
	int					handler_flag;
	char				book[BUFFER_SIZE + 1];
	int					book_size;
	int					book_index;
	int					word_size;
	int					bit_index;
	int					check_num;
}
						t_signal;

int		receive_vefify(int signo, siginfo_t *siginfo, t_signal *sig);
int		receive_data(int signo, siginfo_t *siginfo, t_signal *sig);
int		receive_len(int signo, siginfo_t *siginfo, t_signal *sig);
int		receive_start(int signo, siginfo_t *siginfo, t_signal *sig);

int		send_endsig(siginfo_t *siginfo);
int		send_verify(siginfo_t *siginfo, t_signal *sig);
int		send_data(int signo, siginfo_t *siginfo, t_signal *sig);
int		send_len(siginfo_t *siginfo, t_signal *sig);

void	init_handler(struct sigaction *act, void(*fp));
void	init_t_signal(t_signal *sig);
void	exit_message(char *s, int i);

void	init_int_to_bit(int *cur_i, int *bit_index, int signo);
void	init_str_to_bit(t_signal *sig, int signo);
int		data_branch(t_signal *sig, siginfo_t *siginfo);
int		check_num_verify(t_signal *sig);
#endif
