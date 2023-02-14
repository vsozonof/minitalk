# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 21:33:43 by vsozonof          #+#    #+#              #
#    Updated: 2023/02/14 14:05:08 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f
HEADER = includes/ft_printf.h \

COLOUR_GREEN=\033[0;32m
COLOUR_END=\033[0m

SRCS = 	srcs/ft_putstr.c \
		srcs/ft_putnbr.c \
		srcs/ft_putnbr_hexa.c \
		srcs/ft_strlen.c \
		srcs/ft_pointer_handler.c \
		srcs/ft_printf.c \
		
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(HEADER)
		@echo "$(COLOUR_GREEN)******        CREATING LIBRARY        ******$(COLOUR_END)"
		$(AR) $@ $^
		@echo "$(COLOUR_GREEN)******        LIBRARY CREATED         ******$(COLOUR_END)"

all: $(NAME)
     
clean:
		$(RM) $(OBJS) 

fclean: 
		$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re