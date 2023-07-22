/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 14:45:15 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/21 20:17:24 by jiwkim2          ###   ########seoul.kr  */
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
	game->out = 0;
	game->exit = 0;
	game->position = 0;
}

int main(int argc, char **argv)
{
    t_game  game;
    int	fd;
	

    check_arg(argc, argv[1]);
    set_t_game(&game);
    
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