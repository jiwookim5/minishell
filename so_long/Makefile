CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
SRCS =  ft_error.c ft_split.c ft_strlen.c ft_strncmp.c \
		get_next_line_utils.c get_next_line.c so_long.c\
		check_map.c dfs.c get_gnl_map.c move_func.c move_player.c\
		categorize_case.c check_c_p_e_ones.c check_dfs.c check_arg.c

MLX_DIR = ./mlx
MLX_FLAG	= -Lmlx -lmlx  -framework OpenGL -framework Appkit

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAG) -o $(NAME)

%.o : %.c
	make -C ./mlx
	$(CC) $(CFLAGS) -Imlx -c -o $@ $<

clean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)

fclean:
	$(MAKE) -C $(MLX_DIR) clean
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
