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
	}
	info->p_i = 0;
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
    free(name);
	return NULL;
}

char *change_quote(char *program, char **env)
{
    int i = 0;
    char *name;
    char *value;
	int j = 0;

    name = ft_strdup(&(program[i]));
	 while (name[j])
    {
        if (name[j] == '\"' || name[j] == '\'')
        {
            while (name[j])
            {
                name[j] = '\0';
                j++;
            }
            break;
        }
        j++;
    }
	printf("namee   :  %s\n", name);
	printf("namee   :  %s\n", name);
    while (env[i])
    {
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
    free(name);
	return (NULL);
}
void remove_quotes(char *str, int flag)
{
    int len ;
    int i;
	int j;

	len = ft_strlen(str);
    j = 0;
	i = 0;
	if (flag == 1)
	{
		while (i < len )
    	{
        	if (str[i] != '\"')
     		{
            	str[j++] = str[i];
        	}
			i++;
   		}
	}
	if (flag == 0)
	{
		while (i < len)
    	{
     		if (str[i] != '\'')
        	{
    			str[j++] = str[i];
        	}
			i++;
    	}
	}
    str[j] = '\0';
}

char	*ft_strchr_plus(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			s++;
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}




char	*ft_strcat(char *dest, char *src)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
			a++;
	while (src[b] != '\0')
	{
				dest[a] = src[b];
				a++;
				b++;
	}
			dest[a] = '\0';
	return (dest);
}


int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		|| ((c >= '0') && (c <= '9')))
		return (1);
	else
		return (0);
}


void remove_space(char *str)
{
    int len ;
    int i;
	int j;

	len = ft_strlen(str);
    j = 0;
	i = 0;
	while (i < len)
    	{
    	if (str[i] != ' ')
    	{
    		str[j++] = str[i];
    	}
		i++;
    }
    str[j] = '\0';
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

	ft_memset(buff, 0, 100000);
	(void)env;
	cmd = NULL;
    crr = node->next;
	while (crr != NULL )
    {
       	cmd = crr->content;
		quote = 0;
		i = 0;
		j = 0;
     	while (cmd->program[i][j])
    	{
			if (cmd->program[i][j] == quote)
				quote = 0;
			else if (quote == 0 && (cmd->program[i][j] == '\'' || cmd->program[i][j] == '\"'))
			{
				printf("22222\n");
				quote = cmd->program[i][j];
			}
			else if (quote == 0 )
			{
				printf("j1211111111\n");
				buff[k++] = cmd->program[i][j];
			}
			else if (quote != '\'' && cmd->program[i][j] == '$' && cmd->program[i][j + 1])
			{
				check_split( &k, set_env_to_buf(env,
						find_env(cmd->program[i], &j), buff), &idx ,quote);
			}
			else
				buff[k++] = cmd->program[i][j];

		if (cmd->program[i][j] == '\0')
			i++;
		j++;
		}
		printf("bufffffffff =  = %s\n", buff);
    	cmd->program[i] = buff;
		crr = crr->next;
    }
}

t_list *parsing(char *line, char **env)
{
	t_list *node;
	t_parsing info;
	char *cmd;

	cmd = ft_strtrim(line, " ");
	printf("cmd ::::: %s\n", cmd);
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
	parsing_second(node, env);
	t_list *current = node;
    int node_num = 1;

    while (current != NULL)
	{
        t_cmd *cmd = (t_cmd *)current->content;
        printf("Node %d :\n", node_num);
        if (cmd != NULL) 
		{
            for (int i = 0; cmd->program[i] != NULL; i++)
			{
                printf("  program : %s\n", cmd->program[i]);
            }
            printf("  flag : %d\n", cmd->flag);
        }
        current = current->next;
        node_num++;
    }
	return(NULL);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	a;

	a = 0;
	while (src[a] != '\0' && a < n)
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
			a++;
	}
	return (dest);
}


int		minishell(char **env)
{
	char	*line;
	char quot_b;
	char quot_s;
	int k ;
	int y ;

	line = NULL;
	while (1)
	{
		k = 0;
		y = 0;
		quot_s = 0;
		quot_b = 0;
		line = readline("minishell $ ");
		add_history(line);
		if (!line)
		{
			printf("error\n");
			exit(0);
		}

		printf("lline : %s\n",line);
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

/**
 * $USER 확장
 * "$USER"'$USER' -> segfault
 * "$USER""$USER" -> jiwkim2
 * '$USER'"$USER" -> $USER$USER
 * $$, $? 처리
 * 
 * 
 * '"$USER"'"'$USER'"
*/


