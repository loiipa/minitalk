# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjang <cjang@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 01:54:02 by cjang             #+#    #+#              #
#    Updated: 2021/07/27 01:23:18 by cjang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = libft
LIBFT_A = libft/libft.a

SERVER = server.c
CLIENT = client.c
SRCS_SERVER = server_utils1.c server_utils2.c
SRCS_CLIENT = client_utils.c
SRCS = minitalk_utils.c

SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c
SRCS_SERVER_BONUS = server_utils1_bonus.c server_utils2_bonus.c
SRCS_CLIENT_BONUS = client_utils_bonus.c
SRCS_BONUS = minitalk_utils_bonus.c

NAME = minitalk.a
NAME_BONUS = minitalk_bonus.a
NAME_SERVER = server
NAME_CLIENT = client

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS = $(SRCS:.c=.o)

OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)
OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)
	$(CC) $(CFLAGS) $(SERVER) $(NAME) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(CLIENT) $(NAME) -o $(NAME_CLIENT)

$(NAME): $(OBJS) $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT)
	cp $(LIBFT_A) ./$(NAME)
	ar rc $@ $^

bonus: $(NAME_BONUS)
	$(CC) $(CFLAGS) $(SERVER_BONUS) $(NAME_BONUS) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(CLIENT_BONUS) $(NAME_BONUS) -o $(NAME_CLIENT)

$(NAME_BONUS): $(OBJS_BONUS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS)
	make -C $(LIBFT)
	cp $(LIBFT_A) ./$(NAME_BONUS)
	ar rc $@ $^

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT) $(OBJS) $(OBJS_SERVER_BONUS) $(OBJS_CLIENT_BONUS) $(OBJS_BONUS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS) $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY:
	all bonus clean fclean re
