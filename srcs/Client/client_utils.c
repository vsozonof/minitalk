/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 01:17:59 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/27 01:33:40 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

sig_atomic_t	g_sig_client = 0;

void	ft_len_sender(int pid, int len)
{
	while (len > 0)
	{
		g_sig_client = 0;
		kill(pid, SIGUSR1);
		len--;
		while (!g_sig_client)
			usleep(1);
	}
	kill(pid, SIGUSR2);
	usleep(500);
}

void	ft_client_bit_handler(int sig, siginfo_t *sig_info, void *context)
{
	(void)sig_info;
	(void)context;
	if (sig == SIGUSR1)
		g_sig_client = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("The string was fully passed to the server.");
		exit(EXIT_SUCCESS);
	}
}

void	ft_char_handler(int pid, unsigned char c)
{
	int				bit_index;
	unsigned char	bit_cmp;

	bit_index = 7;
	bit_cmp = 1u << bit_index;
	while (bit_index >= 0)
	{
		g_sig_client = 0;
		if (bit_cmp & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_sig_client)
			usleep(1);
		bit_index--;
		bit_cmp >>= 1;
	}
}

void	ft_str_handler(int pid, char *str)
{	
	int	i;

	i = -1;
	while (str[++i])
		ft_char_handler(pid, str[i]);
	ft_char_handler(pid, 0);
}
