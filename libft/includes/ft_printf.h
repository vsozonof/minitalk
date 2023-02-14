/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 09:24:43 by vsozonof          #+#    #+#             */
/*   Updated: 2022/12/02 10:38:26 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <limits.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *s);
void	ft_putnbr(long int n);
void	ft_putchar(char c);
void	ft_base_checker(unsigned long int nb, char c);
void	ft_putnbr_hexa(unsigned long int nb, char *base);
void	ft_pointer_converter(void *p);
void	ft_neg_converter(unsigned long int nbr);
size_t	ft_strlen(const char *str);

#endif
