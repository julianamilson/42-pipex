# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:52:21 by jmilson-          #+#    #+#              #
#    Updated: 2022/01/13 22:27:27 by jmilson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CFLAGS = -g -Wall -Wextra -Werror -std=c11 -ggdb3

CC = gcc

SRC = treating_cmd.c pipex_utils.c pipex_utils_2.c pipex_utils_3.c messages.c

INCLUDES = -I ./

OBJS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) pipex.c -o $(NAME) $(OBJS) $(INCLUDES)

%.o:%.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
