/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:42:42 by vsozonof          #+#    #+#             */
/*   Updated: 2023/02/28 08:36:12 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

int			ft_isdigit(char *str);
long		ft_atol(const char *str);
int			ft_error_handler(char *error);
int			ft_overflow_handler(char *str);
int			ft_integer_checker(char *str);
int			ft_arg_checker(int argc, char **argv);
void		ft_str_handler(int pid, char *str);
void		ft_char_handler(int pid, unsigned char c);
void		ft_client_sig_handler(int sig, siginfo_t *sig_info, void *context);
void		ft_init_server(void);
void		ft_serv_sig_handler(int sig, siginfo_t *sig_cl, void *context);

#endif