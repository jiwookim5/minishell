/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:45:15 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 20:27:42 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_player(game, game->x, game->y - 1);
	else if (keycode == KEY_S)
		move_player(game, game->x, game->y + 1);
	else if (keycode == KEY_A)
		move_player(game, game->x - 1, game->y);
	else if (keycode == KEY_D)
		move_player(game, game->x + 1, game->y);
	else if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

int	xx(int i)
{
	i = 0;
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	*line;

	line = "";
	check_arg(argc, argv[1]);
	set_t_game(&game);
	game.map = get_gnl_map(argv[1], &game, line);
	check_map(&game);
	game_init(&game);
	check_dfs(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, \
	(game.map_x - 1) * 64, (game.map_y - 1) * 64, argv[0]);
	show_map(&game);
	mlx_hook(game.mlx_win, X_EVENT_KEY_RELEASE, 0, &key_press, &game);
	mlx_hook(game.mlx_win, X_EVENT, 0, &xx, &game);
	mlx_loop(game.mlx);
	return (0);
}
