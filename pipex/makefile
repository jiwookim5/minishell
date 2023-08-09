CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
SRCS = pipex.c 
SRCS_BONUS = bonus.c

OBJS = $(SRCS:.c=.o)

OBJSB = $(SRCS_BONUS:.c=.o)

all: $(NAME)

# allB: $(NAMEB)

# $(NAMEB): $(OBJSB)
# 	$(CC) $(CFLAGS) $(OBJSB) -o $(NAMEB)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
%.o : %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

# bonus:
# 	$(CC) $(CFLAGS) $(OBJSB) -o $(NAME)

.PHONY: clean fclean all re