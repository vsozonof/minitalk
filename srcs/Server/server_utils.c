/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 03:06:42 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/30 21:47:38 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

//---------------------------------------------------------------------------
//						--- GLOBAL STRUCTURE ---
//---------------------------------------------------------------------------
sig_atomic_t	g_sig_serv = 0;

void	ft_serv_len_receiver(int sig, siginfo_t *sig_cl, void *context)
{
	struct sigaction	sa;

	(void)context;
	if (sig == SIGUSR1)
		g_sig_serv++;
	else if (sig == SIGUSR2)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = &ft_serv_sig_handler;
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(1);
	}
	kill(sig_cl->si_pid, SIGUSR1);
}

void	ft_serv_sig_handler(int sig, siginfo_t *sig_cl, void *context)
{
	static unsigned char	c = 0;
	static int				bit_index = 7;

	(void)context;
	if (sig == SIGUSR1)
		c |= (1 << bit_index);
	else if (sig == SIGUSR2)
		c &= ~(1u << bit_index);
	bit_index--;
	if (bit_index < 0)
	{
		ft_str_creator(bit_index, c, sig_cl);
		c = 0;
		bit_index = 7;
	}
	usleep(50);
	kill(sig_cl->si_pid, SIGUSR1);
}

void	ft_str_creator(int bit_index, unsigned int c, siginfo_t *sig_cl)
{	
	struct sigaction	sa;
	static char			*msg;

	if (bit_index < 0 && c)
		msg = ft_charjoin(msg, c, g_sig_serv);
	else if (bit_index < 0 && !(c))
	{
		kill(sig_cl->si_pid, SIGUSR2);
		msg = ft_charjoin(msg, 0, g_sig_serv);
		ft_printf("%s\n", msg);
		free(msg);
		msg = NULL;
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = &ft_serv_len_receiver;
		if (sigaction(SIGUSR1, &sa, NULL) == -1
			|| sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(1);
		g_sig_serv = 0;
	}
}
