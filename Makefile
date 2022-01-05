# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmilson- <jmilson-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 15:52:21 by jmilson-          #+#    #+#              #
#    Updated: 2022/01/05 13:33:54 by jmilson-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

FLAGS = -g -Wall -Wextra -Werror

CC = gcc

SRCS = main.c \
	pipex.c \
	pipex_utils.c \
	pipex_utils_2.c \
	pipex_utils_3.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS)

$(OBJS): $(SRCS)
		$(CC) $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
