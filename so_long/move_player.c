/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:35 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 20:29:13 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	show_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (++i < game->map_y - 1)
	{
		j = -1;
		while (++j < game->map_x - 1)
			categorize_case(game, i, j);
	}
	if (game->map[game->y][game->x] == game->map[game->exit_y][game->exit_x] \
		&& (game->c_check == game->collectible))
	{	
		exit(0);
	}
}

void	move_player_flag(t_game *game, int xx, int yy)
{
	if (game->map[yy][xx] == '1')
		return ;
	if (game->map[yy][xx] == 'C')
		game->c_check++;
	game->map[yy][xx] = 'P';
	game->map[game->y][game->x] = 'E';
	game->y = yy;
	game->x = xx;
	game->flag = 0;
}

void	move_player_zero(t_game *game, int xx, int yy)
{
	game->map[yy][xx] = 'P';
	game->map[game->y][game->x] = '0';
	game->y = yy;
	game->x = xx;
}

void	move_player_c(t_game *game, int xx, int yy)
{
	game->c_check++;
	game->map[yy][xx] = 'P';
	game->map[game->y][game->x] = '0';
	game->y = yy;
	game->x = xx;
}

void	move_player(t_game *game, int xx, int yy)
{
	if (game->flag == 1)
		move_player_flag(game, xx, yy);
	if (game->map[yy][xx] == '0')
		move_player_zero(game, xx, yy);
	else if (game->map[yy][xx] == '1')
		return ;
	else if (game->map[yy][xx] == 'C')
		move_player_c(game, xx, yy);
	else if (game->map[yy][xx] == 'E')
	{
		if (game->collectible != game->c_check)
			game->flag = 1;
		game->map[yy][xx] = 'P';
		game->map[game->y][game->x] = '0';
		game->y = yy;
		game->x = xx;
	}
	move_func(game);
	show_map(game);
}
