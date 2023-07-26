CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS = so_long.c

MLX_FLAG	:=	-lmlx -framework OpenGL -framework Appkit
MLX = ./minilibx_opengl

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX_A)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -o $^ $(NAME)

clean:
	rm -f $(OBJS)
	cd minilibx_opengl
	rm -f $(OBJS)

fclean:
	rm -f $(NAME)
	rm -f $(OBJS)
	cd minilibx_opengl
	rm -f $(NAME)
	rm -f $(OBJS)

re: fclean all

.PHONY: clean fclean all
