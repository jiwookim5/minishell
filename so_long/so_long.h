/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:00:16 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 20:34:37 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_game	t_game;

struct s_game
{	
	int		empty;
	int		wall;
	int		collectible;
	int		exit;
	int		position;
	char	**map;
	int		map_x;
	int		map_y;
	int		exit_x;
	int		exit_y;
	int		c_check;
	int		x;
	int		y;
	int		e_plus_c;
	void	*mlx;
	void	*mlx_win;
	int		move_count;
	int		flag;
	int		mlx_file_cheak;
};

# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define X_EVENT		17
# define BUFFER_SIZE 42

void	ft_error(void);
int		ft_strrlen(char *str);
char	**ft_free(char **word, size_t wordnum);
size_t	ft_word_count(char const *str, char charset);
char	**ft_word_len(char **word, char const *str, char charset);
char	**split(char **word, char const *str, char charset);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_free_a(char **add);
char	*ft_save(char *add);
char	*ft_extract(char *add);
char	*ft_add(int fd, char *buff, char *add);
char	*get_next_line(int fd);
void	check_arg(int argc, char *argv);
void	set_t_game(t_game *game);
char	**get_gnl_map(char *c, t_game *game, char *line);
int		get_height(char **map);
void	check_rectangular(t_game **game);
int		check_line(char *line);
void	check_wall(t_game **game);
void	check_c_p_e_ones(t_game **game);
void	check_map(t_game *game);
void	game_init(t_game *game);
int		check_move_x(int y, int x, char **map);
int		check_move_y(int x, int y, char **map);
void	dfs(t_game *game, int x, int y, char **map);
char	*ft_strcpy(char *dest, char *src);
void	check_dfs(t_game *game);
void	move_write(unsigned int move);
void	put_img(t_game *game, int x, int y, char *file);
void	categorize_case(t_game *game, int x, int y);
void	show_map(t_game *game);
void	move_player(t_game *game, int xx, int yy);
int		key_press(int keycode, t_game *game);
int		main(int argc, char **argv);
void	move_func(t_game *game);

#endif
