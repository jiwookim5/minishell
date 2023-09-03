/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:48:03 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/30 16:48:03 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = (t_list *)malloc(sizeof(t_list));
	if (res == 0)
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}


void init(t_list **node, t_parsing *info, char *line)
{
	info->p_i = 0;
	info->i = 0;
	info->quote = 0;
	info->j = 0;
	*node = ft_lstnew(NULL);
	info->head = *node;
	info->buff = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
}

void set_buff (t_parsing *info, char *line)
{
	info->buff[info->j++] = line[info->i++];
	info->buff[info->j++] = line[info->i];
}

void set_quote(t_parsing *info, char quot, char buffer)
{
	info->quote = quot;
	info->buff[info->j++] = buffer;
}


void	set_contect(t_parsing *info, char *line, t_list *node, int i)
{
	printf("info->content->program[info->p_i] : %s\n", info->content->program[info->p_i]);
	printf("info->buff : %s\n", info->buff);
	ft_lstadd_back(&(node), ft_lstnew((info->content)));
	if (info->i < ((int)ft_strlen(line) - check_next_is_space(line) - 1))
	{
		(info->content) = ft_calloc(1, sizeof(t_cmd));
		(info->content)->program = ft_calloc(space_count(line) + 2,
		sizeof(char*));
		info->head = ft_lstlast(node);
	}
	info->p_i = 0;
	return (SUCCESS);
}

void parsing_check(char *line, t_parsing *info, t_list *node)
{
	printf("line[i] : %c\n", line[info->i]);
	printf("info->quote : %d\n", info->quote);
	if (line[info->i] == info->quote)
		set_quote(info, 0, line[info->i]);
	else if (info->quote == 0 && (line[info->i] == '\'' || line[info->i] == '\"'))
		set_quote(info, line[info->i], line[info->i]);
	else if (info->quote == 0 && line[info->i] == '|')
		set_contect(info, line, node, 1);
	else
		info->buff[info->j++] = line[info->i];
	printf("buff : %s\n", info->buff);
}

t_list *parsing(char *line)
{
	t_list *node;
	t_parsing info;

	init(&node, &info, line);
	while (line[info.i])
	{
		parsing_check(line, &info, node);
		info.i++;
	}
	if (info.quote != 0)
	{
		printf("fuck\n");
		exit(0);
	}
	return(node);
}

int		minishell(void)
{
	t_list	*cmd_list;
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("minishell $ ");
		// printf("%s\n", line);
		if (!line)
		{
			printf("error\n");
			exit(0);
		}
		cmd_list = parsing(line);
		free(line);
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	minishell();
}

