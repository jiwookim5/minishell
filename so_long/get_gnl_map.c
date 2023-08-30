/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gnl_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:55:04 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 20:26:10 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_count_sub(t_game *game, int line_count, char *line)
{
	line_count = ft_strlen(line);
	game->map_x = line_count;
	return (line_count);
}

void	line_count_wrong_x(char *line, char *all_lines)
{
	free(line);
	free(all_lines);
	exit(1);
}

void	temp_sub(char *temp)
{
	free(temp);
	exit (1);
}

char	*get_gnl_map_sub(t_game *game, char *line, char *all_lines, int fd)
{
	char	*temp;
	int		line_count;

	line_count = 0;
	while (line)
	{
		line = get_next_line(fd);
		game->map_y++;
		if (line_count == 0)
			line_count = line_count_sub(game, line_count, line);
		else if (game->map_x != line_count)
			line_count_wrong_x(line, all_lines);
		if (line == NULL || line[0] == '\n')
		{
			free(line);
			break ;
		}
		temp = ft_strjoin(all_lines, line);
		free(all_lines);
		free(line);
		if (!temp)
			temp_sub(temp);
		all_lines = temp;
	}
	return (all_lines);
}

char	**get_gnl_map(char *c, t_game *game, char *line)
{
	char	*all_lines;
	int		fd;
	char	**aa;

	all_lines = ft_strdup("");
	if (!all_lines)
		exit(1);
	fd = open(c, O_RDONLY);
	if (fd < 0)
	{
		free(all_lines);
		exit(1);
	}
	all_lines = get_gnl_map_sub(game, line, all_lines, fd);
	close(fd);
	aa = ft_split(all_lines, '\n');
	free(all_lines);
	if (!aa)
		exit(1);
	return (aa);
}
