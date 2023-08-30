/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:57:15 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 20:27:04 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
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
	if (!(check_line((*game)->map[i - 1])))
		ft_error();
	i--;
	while (i)
	{
		if ((*game)->map[i][0] != '1')
			ft_error();
		if ((*game)->map[i][ft_strlen((*game)->map[i]) - 1] != '1')
			ft_error();
		i--;
	}
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
	while (y != height)
	{
		x = 0;
		while ((*game)->map[y][x] != '\0')
			x++;
		y++;
		if (backup != 0)
		{
			if (backup != x)
				ft_error();
		}
		else
			backup = x;
	}
}

void	check_map(t_game *game)
{
	check_rectangular(&game);
	check_wall(&game);
	check_c_p_e_ones(&game);
}
