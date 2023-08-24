# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 20:20:58 by jiwkim2           #+#    #+#              #
#    Updated: 2023/08/24 21:58:17 by jiwkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
BONUS_NAME = pipex2
SRCS = pipex.c pipex_utils.c get_cmd.c ft_split.c
SRCS_BONUS = bonus.c bonus_utils.c bonus_utils_sub.c bonus_split.c bonus_here_doc.c\
			bonus_get_next_line.c bonus_get_cmd.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
bonus: $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus