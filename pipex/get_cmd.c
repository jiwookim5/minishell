/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:34:39 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/15 16:49:21 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *commend, char **envp, int i)
{
	char	*path;
	char	*c;
	char	*path_cmd;

	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	path = envp[i] + 5;
	while (path && ft_str_chr(path, ':') > 0)
	{
		c = ft_str_dup(path, ft_str_chr(path, ':'));
		path_cmd = path_join(c, commend);
		if (access(path_cmd, X_OK) == 0)
		{
			free(c);
			return (path_cmd);
		}
		path += ft_str_chr(path, ':') + 1;
		free(path_cmd);
		free(c);
	}
	if (ft_str_chr(path, '\0'))
	{
		c = ft_str_dup(path, ft_str_chr(path, '\0'));
		path_cmd = path_join(c, commend);
		if (access(path_cmd, X_OK) == 0)
		{
			free(c);
			return (path_cmd);
		}
		free(path_cmd);
		free(c);
	}
	return (commend);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	get_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;
	int		i;

	i = 1;
	args = ft_split(cmd, ' ');
	path = get_path(args[0], envp, i);
	if (execve(path, args, envp) == -1)
	{
		write(2, "Command not found: ", 19);
		write(2, cmd, ft_strlen(cmd));
		write(2, "\n", 1);
		exit (1);
	}
}
