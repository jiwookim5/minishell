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

void set_quote(t_parsing *info, char quot, char buffer)
{
	info->quote = quot;
	info->buff[info->j++] = buffer;
}


void	push_args(t_parsing *info)
{
	if (*(info->buff) == 0)
		return ;
	info->content->args[info->args_i] = ft_strdup((info->buff));
	info->content->args[info->args_i + 1] = NULL;
	(info->args_i)++;
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
	info->content->flag = i;
	if (*(info->buff))
		push_args(info);
	if ((info->content->args)[0] == 0 && info->content->flag <= 1)
		exit(0);
	else
	{
		ft_lstadd_back(&node, ft_lstnew(info->content));
		info->content = ft_calloc(1, sizeof(t_cmd));
		info->content->args = ft_calloc(count_token(line) + 1, sizeof(char *));
	}
	info->args_i = 0;
}

void		put_args(t_parsing *info)
{
	if (*(info->buff) == 0)
		return ;
	info->content->args[(info->args_i)] = ft_strdup(info->buff);
	info->content->args[(info->args_i) + 1] = NULL;
	(info->args_i)++;
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
	if (line[info->i] == info->quote)
		set_quote(info, 0, line[info->i]);
	else if (info->quote == 0 && (line[info->i] == '\'' || line[info->i] == '\"'))
		set_quote(info, line[info->i], line[info->i]);
	else if (info->quote == 0 && line[info->i] == '|')
		set_content(info, line, node, PIPE);
	else if (info->quote == 0 && line[info->i] == ';')
		set_content(info, line, node, SEMICOLON_NONE);
	else if (info->quote == 0 && line[info->i] == ' ')
		put_args(info);
	else if (info->quote == 0 && line[info->i] == '>' && line[info->i + 1] != '>')
		set_content(info, line, node, SI_REDI_R);
	else if (info->quote == 0 && line[info->i] == '>' && line[info->i] == '>')
		set_content(info, line, node, DOUB_REDI_R);
	else if (info->quote == 0 && line[info->i] == '<' && line[info->i + 1] != '<')
		set_content(info, line, node, SI_REDI_L);
	else if (info->quote == 0 && line[info->i] == '<' && line[info->i + 1] == '<')
		set_content(info, line, node, DOUB_REDI_L);
	else
		info->buff[info->j++] = line[info->i];
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
	info->args_i = 0;
	info->i = 0;
	info->j = 0;
	info->quote = 0;
	*node = ft_lstnew(NULL);
	info->buff = (char *)malloc((ft_strlen(line) + 1) * sizeof(char));
	info->content = (t_cmd *)malloc(sizeof(t_cmd));
	info->content->args = (char **)malloc((count_token(line) + 2) * sizeof(char*));
}


int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		|| ((c >= '0') && (c <= '9')))
		return (1);
	else
		return (0);
}

char		*find_env(char *str, int *i)
{
	char	*ret;
	int		start;
	int		idx;

	idx = *i + 1;
	start = *i + 1;
	while (str[idx])
		if (ft_isalnum(str[idx]) || str[idx] == '_')
			idx++;
		else
		{
			idx--;
			break ;
		}
	*i = idx;
	ret = ft_substr(str, start, idx - start + 1);
	return (ret);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	char	*c;

	a = 0;
	b = 0;
	c = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (dst[a] != '\0')
		a++;
	while (c[b] != '\0' && a + b + 1 < dstsize)
	{
		dst[a + b] = c[b];
		b++;
	}
	dst[a + b] = '\0';
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
		return (ft_strlen(src) + a);
}


int			check_unset(char *str, char *envv)
{
	int		i;

	i = 0;
	while (str[i] && envv[i] && (str[i] == envv[i]) && (envv[i] != '='))
		i++;
	if ((str[i] == '\0') && (envv[i] == '='))
		return (1);
	return (0);
}

int			set_env_to_buf(char **envv, char *env, char *buf)
{
	int		i;

	i = -1;
	while (envv[++i])
	{
		if (check_unset(env, (char*)envv[i]))
		{
			ft_strlcat(buf,
						(char*)envv[i] + ft_strlen(env) + 1,
						ft_strlen(envv[i]) + ft_strlen(buf));
			break ;
		}
	}
	free(env);
	return ((int)ft_strlen(buf));
}

void		check_split(int *j, int z, int *idx, char quote)
{
	*j = z;
	if (quote != '\"')
		*idx = 1;
}

void parsing_second(t_list *node, char **env)
{
    t_list *crr;
    t_cmd *cmd;
    int i;
    char buff[100000];
    int j;
    int quote;
    int k = 0;
    int idx = -1;

    cmd = NULL;
    crr = node->next;
    while (crr != NULL)
    {
        cmd = crr->content;
        quote = 0;
        i = 0;
		while (cmd->args[i])
        {
            j = 0;
			k = 0;
            while (cmd->args[i][j])
            {
                if (cmd->args[i][j] == quote)
                    quote = 0;
                else if (quote == 0 && (cmd->args[i][j] == '\'' || cmd->args[i][j] == '\"'))
                    quote = cmd->args[i][j];
                else if (quote == '\"' && cmd->args[i][j] == '\\' && cmd->args[i][j + 1] )
                    buff[k++] = cmd->args[i][++j];
                else if (quote == 0 && cmd->args[i][j] == '\\' && cmd->args[i][j + 1])
                    buff[k++] = cmd->args[i][j];
                else if (quote != '\'' && cmd->args[i][j] == '$' && cmd->args[i][j + 1])
                    check_split(&k, set_env_to_buf(env, find_env(cmd->args[i], &j), buff), &idx, quote);
                else
				{
                    buff[k] = cmd->args[i][j];
					k++;
				}
				j++;
            }
            cmd->args[i] = ft_strdup(buff);
            i++;
			ft_memset(buff, 0, 100000);
        }
        crr = crr->next;
    }
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
		info.content->args[(info.args_i)] = ft_strdup(info.buff);
		info.content->args[(info.args_i) + 1] = NULL;
		info.args_i++;
	}
	if (info.quote != 0)
	{
		printf("fuck\n");
		exit(0);
	}
	if (info.args_i)
		ft_lstadd_back(&node, ft_lstnew(info.content));
	parsing_second(node, env);
	//result
	t_list *current = node;
    int node_num = 1;

    while (current != NULL)
	{
        t_cmd *cmd = (t_cmd *)current->content;
        printf("Node %d :\n", node_num);
        if (cmd != NULL) 
		{
            for (int i = 0; cmd->args[i] != NULL; i++)
			{
                printf("  args : %s\n", cmd->args[i]);
            }
            printf("  flag : %d\n", cmd->flag);
        }
        current = current->next;
        node_num++;
    }
	return(NULL);
}


int		minishell(char **env)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = readline("minishell $ ");
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
