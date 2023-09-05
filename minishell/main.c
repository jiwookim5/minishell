/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:44:03 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/09/05 19:30:54 by jiwkim2          ###   ########seoul.kr  */
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

int			space_count(char *str)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	return (count);
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
	info->content = (t_cmd *)malloc(sizeof(t_cmd));
	info->content->program = (char **)malloc((space_count(line) + 2) * sizeof(char*));
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

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		*(char*)(s + i) = '\0';
		i++;
	}
}

char	*ft_strdup(const char *s1)
{
	int		size;
	int		index;
	char	*str;

	size = 0;
	while (s1[size])
		size++;
	if (!(str = malloc(sizeof(*s1) * size + 1)))
		return ((char*)0);
	index = 0;
	while (s1[index])
	{
		str[index] = s1[index];
		index++;
	}
	str[index] = '\0';
	return (str);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

static void	push_program(t_parsing *info)
{
	printf("%d\n", info->p_i);
	info->content->program[info->p_i] = ft_strdup((info->buff));
	info->content->program[info->p_i + 1] = NULL;
	printf("Parsed String: %s\n", info->content->program[info->p_i]);
	(info->p_i)++;
	ft_bzero((info->buff), ft_strlen((info->buff)) + 1);
	info->j = 0;
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return ((char*)0);
}

int			check_next_is_space(char *str)
{
	int		index;
	int		count;

	index = ft_strlen(str) - 1;
	count = 0;
	while ((0 <= index) && (str[index] == ' '))
	{
		if (ft_strchr(";|><", str[index]))
			break ;
		count++;
		index--;
	}
	if (index <= 0)
		count = 0;
	return (count);
}

void	set_contect(t_parsing *info, char *line, t_list *node, int i)
{
	printf("info->buff : %s\n", info->buff);
	info->content->flag = i;
	if (*(info->buff))
		push_program(info);
	else
	{
		ft_lstadd_back(&(node), ft_lstnew((info->content)));
		if (info->i < ((int)ft_strlen(line) - check_next_is_space(line) - 1))
		{
			(info->content) = (t_cmd *)malloc(sizeof(t_cmd));
			(info->content)->program = (char **)malloc((space_count(line) + 2) * sizeof(char *));
			info->head = ft_lstlast(node);
		}
	}
	printf("node : %d\n", *(int*)(node->content));
	printf("line : %s\n", line);
	printf("empty info->buff : %s\n", info->buff);
}

void parsing_check(char *line, t_parsing *info, t_list *node)
{
	// printf("line[i] : %c\n", line[info->i]);
	// printf("info->quote : %d\n", info->quote);
	if (line[info->i] == info->quote)
		set_quote(info, 0, line[info->i]);
	else if (info->quote == 0 && (line[info->i] == '\'' || line[info->i] == '\"'))
		set_quote(info, line[info->i], line[info->i]);
	else if (info->quote == 0 && line[info->i] == '|') 
		set_contect(info, line, node, 1);
	else
		info->buff[info->j++] = line[info->i];
	// printf("buff : %s\n", info->buff);
}

t_list *parsing(char *line)
{
	t_list *node;
	t_parsing info;

	init(&node, &info, line);
	while (line[info.i])
	{
		parsing_check(line, &info, node);
		printf("%d\n", info.content->flag);
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

