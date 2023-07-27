/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:00:16 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/27 17:44:50 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include <stdio.h>

typedef struct s_game	t_game;

struct s_game
{	int		empty;
	int		wall;
	int		collectible;
	int		exit;
	int		position;
	char	**map;
//map_all_x,y;
	int 	map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	int		c_check;
	int		x;
	int 	y;
	int		e_plus_c;
	void	*mlx;
	void	*mlx_win;
	int		move_count;
	int		flag;
};

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

# define BUFFER_SIZE 42



int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);



//main.c
void	check_map(t_game *game);
int	get_height(char **map);
char **get_gnl_map(char *c, t_game *game);
void set_t_game(t_game *game);
void check_arg(int argc, char *argv);
void	ft_error(void);
void	check_rectangular(t_game **game);
int	check_line(char *line);
void	check_wall(t_game **game);
void	check_c_e_p_ones(t_game **game);

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

