# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akouame <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/20 12:15:33 by akouame           #+#    #+#              #
#    Updated: 2022/05/20 12:15:35 by akouame          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = CC
CFLAGS = -Wall -Wextra -Werror
CLIENT = client
SERVER = server
NAME = $(CLIENT) $(SERVER)
SRC_c =  client.c
SRC_s =  server.c
SRCS_BONUS = server_bonus.c client_bonus.c
OBJ_c = client.o
OBJ_s = server.o
OBJ_c_bonus = client_bonus.o
OBJ_s_bonus = server_bonus.o
LIBFT = ./libft/libft.a
PATH_LIBFT = ./libft
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

all: $(NAME)

$(LIBFT): ${PATH_LIBFT}
	make -C ${PATH_LIBFT}

$(SERVER): $(OBJ_s) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_s) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_c) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_c)  $(LIBFT) -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(OBJ_s_bonus) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_s_bonus) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(OBJ_c_bonus) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_c_bonus)  $(LIBFT) -o $(CLIENT_BONUS)
clean:
	rm -f server.o client.o server_bonus.o client_bonus.o
	make clean -C ${PATH_LIBFT}

fclean: clean
	$(RM) $(NAME) $(SERVER_BONUS) $(CLIENT_BONUS)
	make fclean -C ${PATH_LIBFT}

re: fclean all

.PHONY: all clean fclean re

