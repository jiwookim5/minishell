/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:03:29 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 14:31:30 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move_x(int y, int x, char **map)
{
	if (map[y][x] != '1')
		return (1);
	return (0);
}

int	check_move_y(int x, int y, char **map)
{
	if (map[y][x] != '1')
	{
		return (1);
	}
	return (0);
}

void	dfs(t_game *game, int x, int y, char **map)
{
	if (map[y][x] == 'E' || map[y][x] == 'C')
		game->e_plus_c++;
		map[y][x] = '1';
	if (check_move_y(x, y - 1, map) == 1)
		dfs(game, x, y - 1, map);
	if (check_move_y(x, y + 1, map) == 1)
		dfs(game, x, y + 1, map);
	if (check_move_x(y, x - 1, map) == 1)
		dfs(game, x - 1, y, map);
	if (check_move_x(y, x + 1, map) == 1)
		dfs(game, x + 1, y, map);
}
