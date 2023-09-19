/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:44:03 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/09/16 19:29:20 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */
#include "minishell.h"


void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return ((void *)b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	if (n <= 0)
		return (0);
	a = 0;
	while (a1[a] != '\0' && a2[a] != '\0' && a < n - 1)
	{
		if (a1[a] != a2[a])
			break ;
		a++;
	}
	return (a1[a] - a2[a]);
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

// void init(t_list **node, t_parsing *info, char *line, char **env)
// {
// 	int i = 0;
// 	info->p_i = 0;
// 	info->i = 0;
// 	info->j = 0;
// 	info->quote = 0;
// 	*node = ft_lstnew(NULL);
// 	info->buff = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
// 	info->head = *node;
// 	info->content = (t_cmd *)malloc(sizeof(t_cmd));
// 	if (ft_strchr(line, '$'))
// 	{
// 		change_quote(info, env);
// 		i = ft_strlen(info->buff);
// 		info->content->program = (char **)malloc((i + 1) * sizeof(char*));
// 	}
// 	else
// 		info->content->program = (char **)malloc((space_count(line) + 2) * sizeof(char*));
// }

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


static void	push_program(t_parsing *info)
{
	printf("sdfasd\n");
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
		return ;
	}
	printf("here\n");
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

}
static void	*ft_move(void *dst, const void *src, size_t len, size_t i)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	if (dst < src)
	{
		while (i < len)
		{
			a[i] = b[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i)
		{
			a [i - 1] = b [i - 1];
			i--;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == 0 && src == 0)
		return (dst);
	return (ft_move(dst, src, len, i));
}



void init(t_list **node, t_parsing *info, char *line)
{
	info->p_i = 0;
	info->i = 0;
	info->j = 0;
	info->quote = 0;
	*node = ft_lstnew(NULL);
	info->buff = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
	info->head = *node;
	info->content = (t_cmd *)malloc(sizeof(t_cmd));
	info->token_count = 0;
	info->content->program = (char **)malloc((count_token(line) + 2) * sizeof(char*));
}

char *change_quote_small(char **program, char **env)
{
    int i = 0;
    char *name;
    char *value;

    name = ft_strdup(&(program[i][2]));
    name[ft_strlen(name) - 1] = '\0';
	printf("namee   :  %s\n", name);
    while (env[i])
    {
		// printf("progggsagas : %s\n", program[0]);
        if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
        {
			printf("090909090900\n");
            value = ft_strchr(env[i], '=');
            if (value)
            {
                free(name);
                return (ft_strdup(value));
            }
        }
        i++;
    }
	// printf("progggsagas : %s\n", program[i]);
    free(name);
	return NULL;
}

char *change_quote(char **program, char **env)
{
    int i = 0;
    char *name;
    char *value;

    name = ft_strdup(&(program[i][2]));
    name[ft_strlen(name) - 1] = '\0';
	printf("namee   :  %s\n", name);
	printf("namee   :  %s\n", name);
    while (env[i])
    {
		// printf("progggsagas : %s\n", program[0]);
        if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
        {
			printf("name len : %zu\n", ft_strlen(name));
			printf("090909090900\n");
            value = ft_strchr(env[i], '=');
            if (value)
            {
                free(name);
                return (ft_strdup(value + 1));
            }
        }
        i++;
    }
	printf("jiwkim222\n");
	// printf("progggsagas : %s\n", program[i]);
    free(name);
	return (NULL);
}
void remove_quotes(char *str)
{
    int len ;
    int i;
	int j;

	len = ft_strlen(str);
    j = 0;
	i = 0;
    while (i < len)
    {
        if (str[i] != '\"')
        {
            str[j++] = str[i];
        }
		i++;
    }
    str[j] = '\0';
}

/// 다시해

void ft_change(char **program, char **env)
{
	char *change;
	int i;

	i = 0;
	printf("111111\n");
    if (program[0][0] == '\"' && program[0][ft_strlen(program[0]) - 1] == '\"')
    {
        printf("SDfsdfsdfds\n");
        change = change_quote(program, env);
		printf("change ::::: %s\n", change);
		if (change)
        {
            free(program[0]);
            program[0] = change;
        }
		remove_quotes(program[0]);
		printf("23343344334434334           243\n");
		if (program[0][0] == '\'' && program[0][ft_strlen(program[0]) - 1] == '\'')
		{
			change = change_quote_small(program, env);
			change[0] = '\'';
			change[ft_strlen(change)] = '\'';
			program[0] = change;
		}
		printf("programmmm : %s\n", change);
    }
	else if (program[0][0] == '\'' && program[0][ft_strlen(program[0]) - 1] == '\'')
    {
        ft_memmove(program[0], program[0] + 1, ft_strlen(program[0]) - 2);
        program[0][ft_strlen(program[0]) - 2] = '\0';
    }
	printf("222222\n");
}

// void remove_quotes(char *str)
// {
//     int len = strlen(str);
//    if (len >= 2 && ((str[0] == '\"' && str[len - 1] == '\"') ||
//    		 (str[0] == '\'' && str[len - 1] == '\'')))
// 	{
//         ft_memmove(str, str + 1, len - 2);
//         str[len - 2] = '\0';
//     }
// }

void parsing_second(t_list *node, char **env)
{
    t_list *crr;
    t_cmd *cmd;
	int i;
	// int j;

	cmd = NULL;
    crr = node->next;
	// j = 0;
	while (crr != NULL )
    {
       	cmd = crr->content;
		// printf("jiwookim1005 : %c", cmd->program[i][j]);
		i = 0;
     	while (cmd->program[i] != NULL)
    	{
			ft_change(&cmd->program[i], env);
				// remove_quotes(cmd->program[i]);
				// if (cmd->program[i][0] == '\"' && cmd->program[i][ft_strlen(cmd->program[i] - 1)])
				// {
				// 	ft_change(&cmd->program[i], env);
        		// 	remove_quotes(cmd->program[i]);
				// }
				// else if ( )
				
			i++;
    	}
    	crr = crr->next;
    }
	// printf("program[0] : %s\n", cmd->program[0]);
	// printf("program[1] : %s\n", cmd->program[1]);
}

t_list *parsing(char *line, char **env)
{
	t_list *node;
	t_parsing info;
	char *cmd;

	cmd = ft_strtrim(line, " ");
	init(&node, &info, line);
	while (cmd[info.i])
	{
		parsing_check(cmd, &info, node);
		info.i++;
	}
	info.buff[info.i] = '\0';
	info.buff = ft_strtrim(info.buff, " ");
	if (*(info.buff))
	{
		printf("buffffff :%s\n", info.buff);
		printf("ASDfasd\n");
		info.content->program[(info.p_i)] = ft_strdup(info.buff);
		printf("ASDfasssssssssd\n");
		info.content->program[(info.p_i) + 1] = NULL;
		info.p_i++;
	}
	if (*(info.buff))
// {
//     // 여기서 info.buff가 공백일 경우에는 삭제하지 않도록 처리
//     char *trimmed_buff = ft_strtrim(info.buff, " ");
// 	printf("trimmed_buff : %s\n", trimmed_buff);
//     if (*trimmed_buff)
//     {
//         // info.buff가 공백이 아닌 경우 처리
//         info.content->program[(info.p_i)] = ft_strdup(trimmed_buff);
//         info.content->program[(info.p_i) + 1] = NULL;
//         info.p_i++;
//     }
//     else
//     {
//         // info->buff가 공백인 경우 처리 (예를 들어, 모두 공백 문자열인 경우)
//         free(trimmed_buff); // 동적 할당된 문자열 메모리 해제
//     }
// }
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
	// t_list *current = node;
    // int node_num = 1;

    // while (current != NULL)
	// {
    //     t_cmd *cmd = (t_cmd *)current->content;
    //     printf("Node %d:\n", node_num);

    //     if (cmd != NULL) 
	// 	{
    //         for (int i = 0; cmd->program[i] != NULL; i++)
	// 		{
    //             printf("  program: %s\n", cmd->program[i]);
    //         }
    //         printf("  Command Type: %d\n", cmd->flag);

    //     }
    //     current = current->next;
    //     node_num++;
    // }
	printf("head- content : %s\n", info.head->content);
	parsing_second(node, env);

	t_list *current = node;
    int node_num = 1;

    while (current != NULL)
	{
        t_cmd *cmd = (t_cmd *)current->content;
        printf("Node %d :\n", node_num);
        if (cmd != NULL) 
		{
			printf("  flag : %d\n", cmd->flag);
            for (int i = 0; cmd->program[i] != NULL; i++)
			{
                printf("  program : %s\n", cmd->program[i]);
            }
            printf("  flag : %d\n", cmd->flag);
        }
        current = current->next;
        node_num++;
    }
	// t_list *current = node->next; 
	//  t_cmd *cmda = (t_cmd *)current->content;
	// if (cmd != NULL)
	// 	printf("  flag : %d\n",cmda->flag);
	return(NULL);
}


int		minishell(char **env)
{
	char	*line;

	// printf("%s\n", *env);
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
		parsing(line, env);
		free(line);

	}
}

int		main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	minishell(env);
}

