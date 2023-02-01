# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 08:37:07 by vsozonof          #+#    #+#              #
#    Updated: 2023/02/01 08:37:42 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar crs
RM = rm -f
NM = norminette

HEADER = 

SRCS = 	
		
OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
		$(AR) $@ $^

norme: $(SRCS) $(HEADER)
		$(NM) $@ $^

all: $(NAME)

git: norme
		git add .
		git commit -m "last commit"
		git push
     
clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re norme bonus