/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:40:04 by vsozonof          #+#    #+#             */
/*   Updated: 2023/02/27 01:09:54 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

sig_atomic_t	g_flag = 0;

void	ft_client_sig_handler(int sig, siginfo_t *sig_info, void *context)
{
	(void)sig;
	(void)sig_info;
	(void)context;
	if (sig == SIGUSR1)
	{
		g_flag = 1;
		ft_printf("sig recu\n");
	}
}

void	ft_char_handler(int pid, unsigned char c)
{
	int	value;

	value = c;
	while (value >= 0)
	{
		g_flag = 0;
		if (value > 0)
		{
			kill(pid, SIGUSR1);
		}
		if (value == 0)
			return ;
		value--;
		usleep(2000);
		if (g_flag == 0)
			pause();
	}
}

void	ft_str_handler(int pid, char *str)
{
	int	i;

	i = -1;
	ft_printf("%i - %s\n", pid, str);
	while (str[++i])
	{
		ft_char_handler(pid, str[i]);
		kill(pid, SIGUSR2);
	}
	ft_char_handler(pid, 0);
}

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
	return (1);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_sigaction = ft_client_sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
    sigaction(SIGUSR1, &sa, NULL);
	if (ft_arg_checker(argc, argv) != 1)
		return (0);
	pid = ft_atol(argv[1]);
	ft_str_handler(pid, argv[2]);
	return (0);
}
