# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedroribeiro <pedroribeiro@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 20:51:10 by procha-r          #+#    #+#              #
#    Updated: 2025/03/22 10:13:52 by pedroribeir      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server
CLIENT = client

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

FT_PRINTF_DIR = ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
INCLUDES = -I$(FT_PRINTF_DIR)/includes -I$(FT_PRINTF_DIR)/libft/includes

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(SERVER): $(OBJ_SERVER) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJ_SERVER) $(FT_PRINTF)

$(CLIENT): $(OBJ_CLIENT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(FT_PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	$(MAKE) -C $(FT_PRINTF_DIR) clean

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus