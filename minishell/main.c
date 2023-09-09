/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:44:03 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/09/09 18:25:48 by jiwkim2          ###   ########seoul.kr  */
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
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

static void	push_program(t_parsing *info)
{
	if (*(info->buff) == 0)
		return ;
	printf("%d\n", info->p_i);
	info->content->program[info->p_i] = ft_strdup((info->buff));
	info->content->program[info->p_i + 1] = NULL;
	printf("Parsed String: %s\n", info->content->program[info->p_i]);
	(info->p_i)++;
	ft_bzero((info->buff), ft_strlen((info->buff)) + 1);
	info->j = 0;
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

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(size * count);
	if (p == NULL)
		return (NULL);
	while (i < size * count)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
char	*ft_strtok(char *str, char sepa)
{
	static char	*stock = NULL;
	char		*p;
	int			i;

	i = 0;
	p = NULL;
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0')
	{
		if (i == 0 && *stock != sepa)
		{
			i = 1;
			p = stock;
		}
		else if (i == 1 && *stock == sepa)
		{
			*stock = '\0';
			stock += 1;
			break ;
		}
		stock++;
	}
	return (p);
}

void		push_buff(t_parsing *info)
{
	info->content->program[(info->p_i)] = ft_strdup(info->buff);
	info->content->program[(info->p_i) + 1] = NULL;
	(info->p_i)++;
	ft_bzero(info->buff, ft_strlen(info->buff) + 1);
	info->j = 0;
}

int		count_token(char *input)
{
	int		count_token;
	char	*p;

	count_token = 1;
	if (!(p = ft_calloc(ft_strlen(input) + 1, sizeof(char))))
		return (0);
	ft_strcpy(p, input);
	if (ft_strtok(p, ' ') != NULL)
	{
		while (ft_strtok(NULL, ' ') != NULL)
			count_token++;
	}
	free(p);
	return (count_token);
}

void	set_content(t_parsing *info, char *line, t_list *node, int i)
{
	if (line[info->i + 1] == '>' || line[info->i + 1] == '<')
		info->i++;
	printf("info->buff : %s\n", info->buff);
	info->content->flag = i;
	printf("flagflag : %d\n", info->content->flag);
	if (*(info->buff))
		push_program(info);
	printf("program: %s\n", info->content->program[0]);
	if ((info->content->program)[0] == 0 && info->content->flag <= 1)
		exit(0);
	else
	{
		ft_lstadd_back(&node, ft_lstnew(info->content));
		printf("FLAG1 : %d\n", info->content->flag);
		info->content = ft_calloc(1, sizeof(t_cmd));
		printf("FLAG2 : %d\n", info->content->flag);
		info->content->program = ft_calloc(count_token(line) + 1, sizeof(char *));
		info->head = ft_lstlast(node);
	}
	info->p_i = 0;
	// printf("node : %d\n", *(int*)(node->content));
	// printf("line : %s\n", line);
	// printf("empty info->buff : %s\n", info->buff);
}

void		put_program(t_parsing *info)
{
	if (*(info->buff) == 0)
	{
		printf("Sdfds\n");
		return ;
	}
	info->content->program[(info->p_i)] = ft_strdup(info->buff);
	info->content->program[(info->p_i) + 1] = NULL;
	(info->p_i)++;
	ft_bzero(info->buff, ft_strlen(info->buff) + 1);
	info->j = 0;
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*res;

	if (len == 0)
	{
		res = malloc(sizeof(char));
		*res = 0;
		return (res);
	}
	if ((res = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	i = 0;
	if (start < (unsigned int)ft_strlen(s))
	{
		while (len--)
			res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}


char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;

	start = 0;
	if (s1 == 0 || set == 0)
		return (0);
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
			start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]))
			end--;
	if (start > end)
		return (ft_strdup(""));
	res = ft_substr(s1, start, end - start);
	return (res);
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
		set_content(info, line, node, 1);
	else if (info->quote == 0 && line[info->i] == ';')
		set_content(info, line, node, 0);
	else if (info->quote == 0 && line[info->i] == ' ')
	{
		put_program(info);
	}
	else if (info->quote == 0 && line[info->i] == '>' && line[info->i + 1] != '>')
		set_content(info, line, node, 2);
	else if (info->quote == 0 && line[info->i] == '>' && line[info->i] == '>')
		set_content(info, line, node, 3);
	else if (info->quote == 0 && line[info->i] == '<' && line[info->i + 1] != '<')
		set_content(info, line, node, 4);
	else if (info->quote == 0 && line[info->i] == '<' && line[info->i + 1] == '<')
		set_content(info, line, node, 5);
	else
	{
		info->buff[info->j++] = line[info->i];
	}
	printf("buff : %s\n", info->buff);

}

t_list *parsing(char *line)
{
	t_list *node;
	t_parsing info;
	char *cmd;

	cmd = ft_strtrim(line, " ");
	init(&node, &info, line);
	while (cmd[info.i])
	{
		parsing_check(cmd, &info, node);
		printf("%d\n", info.content->flag);
		info.i++;
	}
	if (*(info.buff))
		put_program(&info);
	printf("program: %s\n", info.content->program[0]);
	printf("FLAG1 : %d\n", info.content->flag);
	if (info.quote != 0)
	{
		printf("fuck\n");
		exit(0);
	}
	if (info.p_i)
		ft_lstadd_back(&node, ft_lstnew(info.content));
	//result
	t_list *current = node;
    int node_num = 1;

    while (current != NULL)
	{
        t_cmd *cmd = (t_cmd *)current->content;
        printf("Node %d:\n", node_num);

        if (cmd != NULL) 
		{
            for (int i = 0; cmd->program[i] != NULL; i++)
			{
                printf("  program: %s\n", cmd->program[i]);
            }
            printf("  Command Type: %d\n", cmd->flag);

        }
        current = current->next;
        node_num++;
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
		add_history(line);
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

