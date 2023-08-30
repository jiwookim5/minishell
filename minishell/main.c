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

}

void set_quote(t_parsing *info, char quot)
{
	info->quote = quot;
}

void parsing_check(char *line, t_parsing *info)
{
	printf("line[i] : %c\n", line[info->i]);
	printf("info->quote : %d\n", info->quote);
	if (line[info->i] == info->quote)
		set_quote(info, 0);
	else if (info->quote == 0 && (line[info->i] == '\'' || line[info->i] == '\"'))
		set_quote(info, line[info->i]);
}
t_list *parsing(char *line)
{
	t_list *node;
	t_parsing info;

	init(&node, &info, line);
	while (line[info.i])
	{
		printf("sdf\n");
		parsing_check(line, &info);//, node);
		info.i++;
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

