CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = pipex.c 
SRCS_BONUS = bonus.c

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