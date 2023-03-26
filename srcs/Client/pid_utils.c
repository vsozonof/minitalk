/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:26:28 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/24 01:48:50 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_error_handler(char *error)
{
	ft_printf("%s\n", error);
	return (0);
}

int	ft_overflow_handler(char *str)
{
	if (ft_strlen(str) > 10)
		return (0);
	else if (ft_strlen(str) == 10 && ft_integer_checker(str) != 1)
		return (0);
	return (1);
}

int	ft_integer_checker(char *str)
{
	long	max;
	long	pid;

	max = INT_MAX;
	pid = ft_atol(str);
	if (pid > max)
		return (0);
	return (1);
}

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

long	ft_atol(const char *str)
{
	long	var;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	var = 0;
	if (!(str))
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		var = (var * 10) + (str[i] - '0');
		i++;
	}
	return (var * sign);
}
