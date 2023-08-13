CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = pipex.c pipex_utils.c get_cmd.c ft_split.c
SRCS_BONUS = bonus.c bonus_utils.c bonus_utils_sub.c bonus_split.c bonus_here_doc.c\
			bonus_get_next_line.c bonus_get_cmd.c


OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCS_BONUS:.c=.o)

all: $(NAME)


$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
bonus: $(OBJSB)
	$(CC) $(CFLAGS) $(OBJSB) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(OBJSB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus