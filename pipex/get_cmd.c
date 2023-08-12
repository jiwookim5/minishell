/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:34:39 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/12 20:38:56 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *get_path(char *commend, char **envp)
{
    char *path;
    int i;
    char *c;
    char *path_cmd;

    i = 1;
   	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    path = envp[i] + 5;

    while (path && ft_str_chr(path, ':') > 0)
    {
        c = ft_str_dup(path, ft_str_chr(path, ':'));
        path_cmd = path_join(c, commend);
        if (access(path_cmd, X_OK) == 0)
            return (path_cmd);
        path += ft_str_chr(path, ':') + 1;
        free(path_cmd);
    }
    if (ft_str_chr(path, '\0'))
    {
        c = ft_str_dup(path, ft_str_chr(path, '\0'));
        path_cmd = path_join(c, commend);
        if (access(path_cmd, X_OK) == 0)
            return (path_cmd);
    }
    return (commend);
}

void	get_cmd (char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = get_path(args[0], envp);
	//해당 경로에 있는 파일 실행
	execve(path, args, envp);
}