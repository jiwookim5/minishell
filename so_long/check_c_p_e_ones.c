/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_p_e_ones.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:01:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 14:17:03 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_c_p_e_sub(t_game **game, int i, int j)
{
	(*game)->exit_y = i;
	(*game)->exit_x = j;
	(*game)->exit++;
}

void	check_c_p_e_ones(t_game **game)
{
	int	i;
	int	j;

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
				check_c_p_e_sub(game, i, j);
			else if ((*game)->map[i][j] == 'P')
				(*game)->position++;
			else if ((*game)->map[i][j] == 'C')
				(*game)->collectible++;
			j++;
		}
		i--;
	}
	if ((*game)->exit != 1 || (*game)->position != 1 || \
	(*game)->collectible < 1)
		ft_error();
}

void	game_init(t_game *game)
{
	int	xx;
	int	yy;
	int	height;
	int	backup;

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
			break ;
		yy++;
	}
	game->x = xx;
	game->y = yy;
}
