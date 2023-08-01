/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:03:08 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 14:29:22 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	a;

	a = 0;
	while (src[a] != '\0')
	{
		dest[a] = src[a];
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char	**check_dfs_sub(t_game *game)
{
	char	**map_dfs;
	int		i;

	map_dfs = (char **)malloc(sizeof(char *) * (game->map_y));
	if (!map_dfs)
		exit(1);
	i = 0;
	while (i < game->map_y - 1)
	{
		map_dfs[i] = (char *)malloc(sizeof(char) * (game->map_x + 1));
		if (!map_dfs[i])
		{
			while (i > 0)
			{
				i--;
				free(map_dfs[i]);
			}
			free(map_dfs);
			exit(1);
		}
		ft_strcpy(map_dfs[i], game->map[i]);
		i++ ;
	}
	map_dfs[i] = 0;
	return (map_dfs);
}

void	check_dfs(t_game *game)
{
	int		i;
	char	**map_dfs;

	map_dfs = check_dfs_sub(game);
	dfs(game, game->x, game->y, map_dfs);
	i = 0;
	while (map_dfs[i])
	{
		free(map_dfs[i]);
		i++;
	}
	free(map_dfs);
	if (game->e_plus_c != game->exit + game->collectible)
		ft_error();
}
