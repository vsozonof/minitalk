/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:40:04 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/30 18:57:22 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_arg_checker(int argc, char **argv)
{
	if (argc != 3)
		return (ft_error_handler("Error: not enough arguments."));
	else if (ft_isdigit(argv[1]) != 1)
		return (ft_error_handler("Error: invalid input."));
	else if (argv[1][0] == '\0' || argv[2][0] == '\0')
		return (ft_error_handler("Error: invalid input."));
	else if (ft_overflow_handler(argv[1]) != 1)
		return (ft_error_handler("Error: invalid PID."));
	else if (ft_atol(argv[1]) < 10)
		return (ft_error_handler("Error: invalid PID"));
	return (1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = &ft_client_bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	if (ft_arg_checker(argc, argv) != 1)
		return (0);
	pid = ft_atol(argv[1]);
	ft_len_sender(pid, ft_strlen(argv[2]));
	ft_str_handler(pid, argv[2]);
	return (0);
}
