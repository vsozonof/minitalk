/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:39:51 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/26 17:06:09 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_init_server(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_serv_len_receiver;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	ft_printf("PID %d: waiting...\n", getpid());
	while (42)
		usleep(1);
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
