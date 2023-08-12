/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:17:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/12 20:26:39 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


static char	**ft_free(char **word, size_t wordnum)
{
	size_t	i;

	i = 0;
	while (i < wordnum)
	{
		free(word[i]);
		i++;
	}
	free(word);
	return (0);
}

static size_t	ft_word_count(char const *str, char charset)
{
	size_t	count;
	size_t	flag;

	count = 0;
	flag = 0;
	while (*str)
	{
		if (*str != charset && flag == 0)
		{
			flag = 1;
			count++;
		}
		else if (*str == charset)
			flag = 0;
		str++;
	}
	return (count);
}

static char	**ft_word_len(char **word, char const *str, char charset)
{
	size_t	count;
	size_t	wordnum;
	size_t	wordcount;

	wordcount = ft_word_count(str, charset);
	wordnum = 0;
	while (*str)
	{
		count = 0;
		while ((*str != charset) && *(str) != '\0')
		{
			count++;
			str++;
		}
		if (count != 0)
		{
			word[wordnum] = (char *)malloc((count + 1) * sizeof(char));
			if (word[wordnum] == 0)
				return (ft_free(word, wordnum));
			word[wordnum++][count] = '\0';
		}
		while (*str && *str == charset)
			str++;
	}
	return (word);
}

static char	**split(char **word, char const *str, char charset)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*str && *str == charset)
		str++;
	while (*str)
	{
		j = 0;
		while ((*str != charset) && *(str) != '\0')
		{
			word[i][j] = *str;
			j++;
			str++;
		}
		word[i][j] = '\0';
		while (*str && *str == charset)
			str++;
		i++;
	}
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**word;
	size_t		word_count;

	j = 0;
	i = 0;
	word_count = ft_word_count(s, c);
	if (word_count == 0)
	{
		word = (char **)malloc(1 * sizeof(char *));
		if (!word)
			return (ft_free(word, 0));
		word[0] = 0;
		return (word);
	}
	word = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word == 0)
		return (ft_free(word, 0));
	if (ft_word_len (word, s, c) == 0)
		return (0);
	split(word, s, c);
	word[word_count] = 0;
	return (word);
}
void ft_error(void)
{
    write(1, "error\n", 7);
    exit(1);
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

char *ft_route(char *path)
{
    int i;
    char *c;
    int j;

    i = 0;
    j = 0;
    while (path[i] == ':')
        i++;
    c = (char *)malloc(sizeof(char) * i + 1);
    if (!c)
        return(0);
    c[i] = '\0';
    i = 0;
    while(path[j] != ':')
    {
        c[i] = path[j];
        i++;
        j++;
    }
    return(c);
}
int ft_str_chr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    if (str[i] == c)
        return(i);
    return(0);
}

int file_open(char *argv, int i)
{
    int infile;
    int outfile;
    
    if (i == 1)
    {
        infile = open(argv, O_RDONLY);
        if (infile == -1)
            ft_error();
        return(infile);
    }
    else
    {
        outfile = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile == -1)
            ft_error();
        return(outfile);
    }       
}
char *path_join(char *path, char *cmd)
{
    char *c;
    int i;
    int j;

    c = (char *)malloc(sizeof(char) * (ft_str_chr(path, '\0') + ft_str_chr(cmd, '\0')+ 2));
    i = 0;
    j = 0;
    while(path[j] != '\0')
    {
        c[i] = path[j];
        i++;
        j++;
    }
    c[i] = '/';
    i++;
    j = 0;
    while (cmd[j])
    {

        c[i] = cmd[j];
        i++;
        j++;
    }
    c[i]= '\0';
    return(c);
    
}

char	*ft_str_dup (char *str, int n)
{
	char		*c;
	int		i;

	i = 0;
	c = malloc(sizeof(char) * (n + 1));
	while (i < n)
    {
		c[i] = str[i];
        i++;
    }
    c[n] = 0;
	return (c);
}

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

void get_pipe(char *cmd, char **envp)
{
	pid_t pid;
	int pipefd[2];

	pipe(pipefd);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		get_cmd(cmd, envp);
	}
}

int main(int argc, char **argv, char **envp)
{
    t_file file;

    if (argc == 5)
    {
        file.infile = file_open(argv[1], 1);
        file.outfile = file_open(argv[4], 2);

		//infile을 닫고 표준입력파일을 가리키도록 함
		dup2(file.infile, STDIN_FILENO);
		//outfile을 닫고 표준출력파일을 가리키도록 함
        dup2(file.outfile, STDOUT_FILENO);
		get_pipe(argv[2], envp);
		get_cmd(argv[3], envp);
    }
	else
		write(1, "argc error\n", 10);
    return (0);
}