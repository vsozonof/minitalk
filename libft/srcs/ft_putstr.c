/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:29:37 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/23 23:14:12 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstr(char *s)
{
	if (s == NULL)
		return (ft_putstr("(null)"));
	write(1, s, ft_strlen(s));
}
