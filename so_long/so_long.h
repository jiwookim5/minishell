/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:00:16 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/26 21:08:36 by jiwkim2          ###   ########seoul.kr  */
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



// int check_move_x(int y, int x, t_game *game) {
//     if (game->map[y][x] != '1')
//         return 1;
//     return 0;
// }

// int check_move_y(int x, int y, t_game *game) {
//     if (game->map[y][x] != '1') {
//         printf("sdfdxcdxvsdfs\n");
//         return 1;
//     }
//     return 0;
// }

// void dfs(t_game *game, int x, int y, char **map) {
//     printf("x, y : %d, %d\n", x, y);
//     if (map[y][x] == 'E' || map[y][x] == 'C')
//         game->e_plus_c++;

//     printf("e_plus_c : %d\n", game->e_plus_c);

//     if (map[y][x] != 'E') {
//         map[y][x] = '1';
//         if (check_move_y(x, y - 1, game) == 1) {
//             dfs(game, x, y - 1, map);
//         }
//         if (check_move_y(x, y + 1, game) == 1) {
//             dfs(game, x, y + 1, map);
//         }
//         if (check_move_x(y, x - 1, game) == 1) {
//             dfs(game, x - 1, y, map);
//         }
//         if (check_move_x(y, x + 1, game) == 1) {
//             dfs(game, x + 1, y, map);    
//         }
//     } else {
//         map[y][x] = '1';
//     }
// }

// char *ft_strcpy(char *dest, char *src) {
//     int a = 0;
//     while (src[a] != '\0') {
//         dest[a] = src[a];
//         a++;
//     }
//     dest[a] = '\0';
//     return dest;
// }

// void check_dfs(t_game *game) {
//     char **map_dfs;
//     int i, j;

//     map_dfs = (char **)malloc(sizeof(char *) * game->x);
//     if (!map_dfs)
//         exit(1);

//     for (i = 0; i < game->x; i++) {
//         map_dfs[i] = (char *)malloc(sizeof(char) * (game->y + 1));
//         if (!map_dfs[i]) {
//             for (j = 0; j < i; j++) {    
//                 free(map_dfs[j]);
//             }
//             free(map_dfs);
//             exit(1);
//         }
//         ft_strcpy(map_dfs[i], game->map[i]);
//     }

//     dfs(game, game->x, game->y, map_dfs);

//     for (i = 0; i < game->x; i++) {
//         free(map_dfs[i]);
//     }
//     free(map_dfs);

//     printf("ex : %d, co : %d\n", game->exit, game->collectible);
//     if (game->e_plus_c != (game->exit + game->collectible)) {
//         printf("sdfsd\n");
//         exit(1);
//     }
// }