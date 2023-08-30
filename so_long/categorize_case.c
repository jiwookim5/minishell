/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   categorize_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:04:15 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 15:54:18 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_game *game, int x, int y, char *file)
{
	int		img_width;
	int		img_height;
	void	*img;

	img = mlx_xpm_file_to_image(game->mlx, file, &img_width, &img_height);
	if (!img)
	{
		game->mlx_file_cheak++;
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, y * 64, x * 64);
	mlx_destroy_image(game->mlx, img);
}

void	categorize_case(t_game *game, int x, int y)
{
	put_img(game, x, y, "./images/back_ground.xpm");
	if (game->map[x][y] == '1')
		put_img(game, x, y, "./images/tree.xpm");
	else if (game->map[x][y] == 'E')
	{
		if (game->c_check == game->collectible)
			put_img(game, x, y, "./images/exit_fin.xpm");
		else
			put_img(game, x, y, "./images/exit.xpm");
	}
	else if (game->map[x][y] == 'C')
		put_img(game, x, y, "./images/eat.xpm");
	else if (game->map[x][y] == 'P')
		put_img(game, x, y, "./images/player.xpm");
	if (game->mlx_file_cheak > 0)
		ft_error();
}
