# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 15:33:31 by jiwkim2           #+#    #+#              #
#    Updated: 2023/08/26 15:41:50 by jiwkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
NAME_BONUS = pipex_bonus 
SRCS = pipex.c pipex_utils.c get_cmd.c ft_split.c
SRCS_BONUS = utils_sub_bonus_.c utils_bonus.c split_bonus.c pipex_bonus.c here_doc_bonus.c \
			get_next_line_bonus.c get_cmd_bonus.c


OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCS_BONUS:.c=.o)

all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
$(NAME_BONUS): $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(NAME_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: clean fclean all re bonus