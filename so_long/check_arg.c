/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:53:10 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 20:21:13 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_t_game(t_game *game)
{
	game->empty = 0;
	game->wall = 0;
	game->collectible = 0;
	game->exit = 0;
	game->position = 0;
	game->map_x = 0;
	game->map_y = 0;
	game->move_count = 0;
	game->flag = 0;
	game->mlx_file_cheak = 0;
}

int	ft_strrlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (str[i] != '.')
	{
		i--;
		j++;
	}
	j--;
	return (j);
}

void	check_arg(int argc, char *argv)
{
	char	*c;

	if (argc != 2)
		ft_error();
	c = ft_strchr(argv, '.');
	if (c && (ft_strncmp(c, ".ber", 4) != 0))
		ft_error();
}
