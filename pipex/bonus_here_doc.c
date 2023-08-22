/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:52:07 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/17 17:35:16 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc_sub(char *argv)
{
	int		file;
	char	*line;

	file = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
	{
		ft_error();
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
		{
			ft_error();
		}
		if (!ft_strncmp(argv, line, ft_strlen(argv)) && \
			ft_strlen(argv) == ft_strlen(line) - 1)
			break ;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
}

void	here_doc(int argc, char **argv, t_file *file)
{
	here_doc_sub(argv[2]);
	file->infile = open(".here_doc_tmp", O_RDONLY);
	if (file->infile < 0)
	{
		perror("Error opening file");
		exit(1);
	}
	file->outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (file->outfile < 0)
	{
		perror("Error opening file");
		exit(1);
	}
}
