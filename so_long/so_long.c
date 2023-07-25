/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:45:15 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/25 21:36:44 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_arg(int argc, char *argv)
{
    char *c;

    if (argc != 2)
      ft_error();
	  c = ft_strchr(argv, '.');
	  if ((c && ft_strncmp(c, ".ber", 3)))
		  ft_error();
}

void set_t_game(t_game *game)
{
 	game->empty = 0;
	game->wall = 0;
	game->collectible = 0;
	game->exit = 0;
	game->position = 0;
	game->e_plus_c = 0;
}

char **get_gnl_map(char *c)
{
	char	*line;
	char	*all_lines;
	int		fd;

	line = "";
	all_lines = ft_strdup("");
	fd = open(c, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
 			break ;
		all_lines = ft_strjoin(all_lines, line);
	}
	close(fd);
	if (all_lines[0] == '\0')
		ft_error();
	return (ft_split(all_lines, '\n'));
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	check_rectangular(t_game **game)
{
	int	y;
	int	x;
	int	height;
	int	backup;

	y = 0;
	backup = 0;
	height = get_height((*game)->map);
	printf("height : %d\n", height);
	while (y != height)
	{
		x = 0;
		while ((*game)->map[y][x] != '\0')
			x++;
		y++;
		if (backup != 0)
		{
			printf("backup : %d, x : %d\n", backup, x);
			if (backup != x)
				ft_error();
		}
		else
			backup = x;
	}
}

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}


void	check_wall(t_game **game)
{
	int		i;
	
	if (!(check_line((*game)->map[0])))
		ft_error();
	i = get_height((*game)->map);
	printf("i : %d\n", i);
	if (!(check_line((*game)->map[i - 1])))
		ft_error();
	i--;
	while (i)
	{
		if ((*game)->map[i][0] != '1')
			ft_error();
		if ((*game)->map[i][ft_strlen((*game)->map[i]) -1 ] != '1')
			ft_error();
		i--;
	}

}

void	check_c_p_e_ones(t_game **game)
{
	int i;
	int j;

	(*game)->exit = 0;
	(*game)->collectible = 0;
	(*game)->position = 0;
	i = get_height((*game)->map) - 1;
	while (i)
	{
		j = 0;
		while ((*game)->map[i][j] != '\0')
		{
			if ((*game)->map[i][j] == 'E')
				(*game)->exit++;
			else if ((*game)->map[i][j] == 'P')
				(*game)->position++;
			else if ((*game)->map[i][j] == 'C')
				(*game)->collectible++;
			j++;
		}
		i--;
	}
	if ((*game)->exit != 1 || (*game)->position != 1 || (*game)->collectible < 1)
		ft_error();
}

void	check_map(t_game *game)
{
	check_rectangular(&game);
	printf("ddd\n");
	check_wall(&game);
	check_c_p_e_ones(&game);
}

int				key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->y++;
	else if (keycode == KEY_S)
		game->y--;
	else if (keycode == KEY_A)
		game->x--;
	else if (keycode == KEY_D)
		game->x++;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("x: %d, y: %d\n", game->x, game->y);
	return (0);
}

void			game_init(t_game *game)
{
	int xx;
	int yy;
	int height;
	int backup;
	
	yy = 0;
	backup = 0;
	height = get_height((game)->map);
	while (yy != height)
	{
		xx = 0;
		while ((game)->map[yy][xx] != 'P')
		{
			if ((game)->map[yy][xx] == '\0')
				break ;
			xx++ ;
		}
		if ((game)->map[yy][xx] == 'P')
			break;
		yy++;
	}
	game->x = xx;
	game->y = yy;
	printf("x, y : %d, %d\n", game->x, game->y);
}

int	check_move_x(int y, int x, t_game **game)
{
	if ((*game)->map[y][x] != '1')
		return (1);
	return (0);
}

int	check_move_y(int x, int y, t_game **game)
{
	if ((*game)->map[y][x] != '1')
	{
		printf("sdfdxcdxvsdfs\n");
		return (1);
	}
	return (0);
}

void	dfs(t_game **game, int x, int y, char *map)
{
	printf("x, y : %d, %d\n", (*game)->x, (*game)->y);
	if ((*game)->map[y][x] == 'E' || (*game)->map[y][x] == 'C')
		(*game)->e_plus_c++;
	printf("e_plus_c : %d\n", (*game)->e_plus_c);
	if ((*game)->map[y][x] != 'E')
	{
		(*game)->map[y][x] = '1';
		if (check_move_y(x, y - 1, game) == 1)
		{
			dfs(game, x, y, map);
		}
		if (check_move_y(x, y + 1, game) == 1)
			{
				dfs(game, x, y, map);
			}
		if (check_move_x(y, x - 1, game) == 1)
			{
				dfs(game, x, y, map);
			}
		if (check_move_x(y, y + 1, game) == 1)
		{
			dfs(game, x, y, map);	
		}
	}
	else
		(*game)->map[y][x] = '1';
}

void	check_dfs(t_game *game)
{
	char	**map_dfs;
	int 	i;
	
	i = 0;
	map_dfs = (char **)malloc(sizeof(char *) * game->x);
	if (!map_dfs)
		ft_error();
	while (i < game->x)
	{
		map_dfs[i] = (char *)malloc(sizeof(char) * game->y);
		if (!map_dfs[i])
			ft_error();	
		i++;
	}
	map_dfs = game->map;
	dfs(&game, game->x, game->y, *map_dfs);
	free(map_dfs);
	printf("ex : %d, co : %d\n", game->exit, game->collectible);
	if (game->e_plus_c != (game->exit + game->collectible))
	{
		printf("sdfsd\n");
		ft_error();
	}
}

int main(int argc, char **argv)
{
    t_game  game;
	void *mlx;
  	void *mlx_win;
	

    check_arg(argc, argv[1]);
	set_t_game(&game);
	game.map = get_gnl_map(argv[1]);
	check_map(&game);
	game_init(&game);
	check_dfs(&game);
	exit(1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello 42 Seoul");
	mlx_hook(mlx_win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_loop(mlx_win);
	
    return (0);
}




// typedef struct s_data {
//   void *img;
//   char *addr;
//   int bits_per_pixel;
//   int line_length;
//   int endian;
// } t_data;

// void  my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//   char *dst;

//   dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//   *(unsigned int*)dst = color;
// }

// int main(void)
// {
//   void *mlx;
//   void *mlx_win;
//   t_data img;

//   mlx = mlx_init();
//   mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello 42 Seoul");
//   img.img = mlx_new_image(mlx, 1920, 1080);
//   img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//   my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
//   mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//   mlx_loop(mlx);
// }