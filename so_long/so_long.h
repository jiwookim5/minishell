/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:00:16 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/23 17:45:47 by jiwkim2          ###   ########seoul.kr  */
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
};

# define BUFFER_SIZE 42

int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);



//main.c
void	check_map(t_game *game);
int	get_height(char **map);
char **get_gnl_map(char *c);
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
