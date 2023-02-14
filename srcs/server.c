/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:39:51 by vsozonof          #+#    #+#             */
/*   Updated: 2023/02/14 19:30:53 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	g_signal = 0;

void	sig_handler(int sig)
{
	g_signal += 1;
	(void)sig;
}

int	main(void)
{
	struct sigaction	sa;

	g_signal = 0;
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	while (1)
	{
		ft_printf("%i - PID %d: waiting...\n", g_signal, getpid());
		sleep(5);
	}
	ft_printf("%i - DONE", g_signal);
}