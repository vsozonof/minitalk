/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:39:51 by vsozonof          #+#    #+#             */
/*   Updated: 2023/02/09 13:58:31 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	sig_handler(int sig)
{
	g_signal = 1;
}

int	main(void)
{
	struct sigaction	sa;

	g_signal = 0;
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL))
		exit(1);
	while (!g_signal)
	{
		ft_printf("%i - PID %d: waiting...\n", g_signal, getpid());
		sleep(5);
	}
	ft_printf("%i - DONE", g_signal);
}