CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
SRCS =ft_decide_cspx.c ft_distinguish.c ft_printf.c ft_put_series.c\
		ft_str_series.c ft_decide_diu.c ft_decide_xx.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME): $(OBJS)
	ar rc $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all