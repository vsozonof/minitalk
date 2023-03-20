/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:39:51 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/20 10:48:08 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

sig_atomic_t	g_sig_serv = 0;

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
	kill(sig_cl->si_pid, SIGUSR1);
}

void	ft_str_creator(int bit_index, unsigned int c, siginfo_t *sig_cl)
{	
	static char	*msg;
	char		*tmp;

	if (bit_index < 0 && c)
		msg = ft_charjoin(msg, c);
	else if (bit_index < 0 && !(c))
	{
		kill(sig_cl->si_pid, SIGUSR2);
		ft_printf("%s\n", msg);
	}
}

void	ft_init_server(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_serv_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	ft_printf("PID %d: waiting...\n", getpid());
	while (42)
		usleep(42000);
}

int	main(void)
{
	ft_printf("\033[0;35m");
	ft_printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	ft_printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝\n");
	ft_printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	ft_printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n\n");
	ft_printf("\033[0;37m");
	ft_init_server();
}
