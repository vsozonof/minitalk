/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:42:42 by vsozonof          #+#    #+#             */
/*   Updated: 2023/03/26 16:30:06 by vsozonof         ###   ########.fr       */
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

//---------------------------------------------------------------------------
//						--- GLOBAL VARIABLES ---
//---------------------------------------------------------------------------

extern sig_atomic_t	g_sig_client;
extern sig_atomic_t	g_sig_serv;

//---------------------------------------------------------------------------
//						--- CLIENT RELATED FUNCTIONS ---
//---------------------------------------------------------------------------

// ARGUMENTS VERIFICATION
//-------------------------

int			ft_isdigit(char *str);
long		ft_atol(const char *str);
int			ft_error_handler(char *error);
int			ft_overflow_handler(char *str);
int			ft_integer_checker(char *str);
int			ft_arg_checker(int argc, char **argv);

// "PHASE 1" FUNCTIONS - GETTING THE STRING LEN
//----------------------------------------------
void		ft_len_sender(int pid, int len);

// -> "PHASE 2" FUNCTIONS - SENDING CHARACTERS' BITS
//---------------------------------------------------
void		ft_str_handler(int pid, char *str);
void		ft_char_handler(int pid, unsigned char c);
void		ft_client_bit_handler(int sig, siginfo_t *sig_info, void *context);

//---------------------------------------------------------------------------
//						--- SERVER RELATED FUNCTIONS ---
//---------------------------------------------------------------------------

// STARTING THE SERVER
//---------------------

void		ft_init_server(void);
// -> "PHASE 1" FUNCTIONS - GETTING THE STRING LEN
//-------------------------------------------------
void		ft_serv_len_receiver(int sig, siginfo_t *sig_cl, void *context);

// -> "PHASE 2" FUNCTIONS - RECEIVING AND ASSEMBLING THE STRING
//--------------------------------------------------------------
void		ft_serv_sig_handler(int sig, siginfo_t *sig_cl, void *context);
void		ft_str_creator(int bit_index, unsigned int c, siginfo_t *sig_cl);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_charjoin(char *str, char c, int len);
int			ft_status_checker(int pid);

#endif