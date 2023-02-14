/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:42:42 by vsozonof          #+#    #+#             */
/*   Updated: 2023/02/14 18:25:13 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int			ft_isdigit(char *str);
int			ft_atoi(const char *str);
int			ft_error_handler(char *error);
int			ft_arg_checker(int argc, char **argv);

#endif