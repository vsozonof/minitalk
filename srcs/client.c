/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:40:04 by vsozonof          #+#    #+#             */
/*   Updated: 2023/02/20 12:38:58 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

int	ft_char_handler(int pid, unsigned char c)
{
	ft_printf("%c\n", c);
	// aaaaaaaa
}

void	ft_str_handler(int pid, char *str)
{
	int	i;

	i = -1;
	ft_printf("%i - %s\n", pid, str);
	while (str[++i])
		ft_char_handler(pid, str[i]);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (ft_arg_checker(argc, argv) != 1)
		return (0);
	pid = ft_atol(argv[1]);
	ft_str_handler(pid, argv[2]);
	return (0);
}
