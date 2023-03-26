# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 08:37:07 by vsozonof          #+#    #+#              #
#    Updated: 2023/03/24 03:40:04 by vsozonof         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable files name
SERV_EXEC = server
CLIENT_EXEC = client
	
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -f

# Colors
COLOUR_GREEN =\033[0;32m
COLOUR_END =\033[0m

SRCS_CLIENT = srcs/client.c \
			  srcs/pid_utils.c \
			  srcs/client_utils.c \

SRCS_SERVER = srcs/server.c \
			  srcs/string_utils.c \
			  srcs/server_utils.c \

SRCS_LIBFT = libft/libftprintf.a \
		
all: init $(SERV_EXEC) $(CLIENT_EXEC)

init:
		@echo "$(COLOUR_GREEN)****** STARTING COMPILATION ******$(COLOUR_END)"
		make all -C ./libft

$(SERV_EXEC): $(SRCS_SERVER) $(HEADER)
	@echo "$(COLOUR_GREEN)******    CREATING SERVER    ******$(COLOUR_END)"
	$(CC) $(CFLAGS) $(SRCS_SERVER) $(SRCS_LIBFT) -o $(SERV_EXEC)

$(CLIENT_EXEC): $(SRCS_CLIENT) $(HEADER)
	@echo "$(COLOUR_GREEN)******    CREATING CLIENT    ******$(COLOUR_END)"
	$(CC) $(CFLAGS) $(SRCS_CLIENT) $(SRCS_LIBFT) -o $(CLIENT_EXEC)

clean:
		@echo "$(COLOUR_GREEN)****** INITIATING CLEAN  ******$(COLOUR_END)"
		make clean -C ./libft
		@echo "$(COLOUR_GREEN)******   CLEAN COMPLETE  ******$(COLOUR_END)"

fclean: 
		@echo "$(COLOUR_GREEN)****** INITIATING FCLEAN ******$(COLOUR_END)"
		make fclean -C ./libft
		$(RM) $(SERV_EXEC) $(CLIENT_EXEC)
		@echo "$(COLOUR_GREEN)******  FCLEAN COMPLETE  ******$(COLOUR_END)"
		
re: fclean all

.PHONY: all clean fclean re init