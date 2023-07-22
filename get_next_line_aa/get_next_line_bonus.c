/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:52:16 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/04/07 11:03:51 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_free(char **add)
{
	free(*add);
	*add = 0;
	return (0);
}

static char	*ft_save(char *add)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!ft_strchr(add, '\n'))
		return (ft_free(&add));
	if (add[0] == 0)
		return (0);
	while (add[i] != '\0' && add[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(add) - i) + 1);
	if (s == 0)
		return (ft_free(&add));
	i++;
	while (add[i])
		s[j++] = add[i++];
	s[j] = '\0';
	ft_free(&add);
	return (s);
}

static char	*ft_extract(char *add)
{
	int		i;
	char	*result;

	i = 0;
	while (add[i] != '\n' && add[i] != '\0')
		i++;
	if (add[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (add[i] != '\0')
	{
		result[i] = add[i];
		if (add[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_add(int fd, char *buff, char *add)
{
	int		byte;
	char	*temp;

	if (add == 0)
		add = ft_strdup("");
	byte = 1;
	while (!ft_strchr(add, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (add == 0)
			add = ft_strdup("");
		if ((byte == -1) || (byte == 0 && add[0] == 0))
		{
			ft_free(&add);
			free(buff);
			return (0);
		}
		buff[byte] = '\0';
		temp = add;
		add = ft_strjoin(add, buff);
		free(temp);
	}
	free(buff);
	return (add);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*add[OPENMAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPENMAX)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == 0)
		return (ft_free(&add[fd]));
	add[fd] = ft_add(fd, buff, add[fd]);
	if (add[fd] == 0)
		return (0);
	line = ft_extract(add[fd]);
	if (line == 0)
	{
		ft_free(&add[fd]);
		return (0);
	}
	add[fd] = ft_save(add[fd]);
	return (line);
}
