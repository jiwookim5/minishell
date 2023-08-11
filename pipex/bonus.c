/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:01:48 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/11 19:03:21 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	char	*temp;

	i = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	temp = res;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	char	*a;
	char	b;
	int		i;

	if (str == 0)
		return (0);
	a = (char *)str;
	b = (char)c;
	i = 0;
	while (a[i] != b)
	{
		if (a[i] == '\0')
			return (0);
		i++;
	}
	return (&a[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	char		*res;
	size_t		s2_len;

	if (s1 == 0 || s2 == 0)
	{
		res = (char *)malloc(sizeof(char) + 1);
		if (res == 0)
			return (0);
		res[0] = 0;
		return (res);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (res == 0)
		return (0);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	res[s1_len + s2_len] = 0;
	return (res);
}


static char	*ft_free(char **add)
{
	free(*add);
	*add = 0;
	return (0);
}

static char	*ft_save(char *add)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!ft_strchr(add, '\n'))
		return (ft_free(&add));
	if (add[0] == 0)
		return (0);
	while (add[i] != '\0' && add[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (ft_strlen(add) - i) + 1);
	if (s == 0)
		return (ft_free(&add));
	i++;
	while (add[i])
		s[j++] = add[i++];
	s[j] = '\0';
	ft_free(&add);
	return (s);
}

static char	*ft_extract(char *add)
{
	int		i;
	char	*result;

	i = 0;
	while (add[i] != '\n' && add[i] != '\0')
		i++;
	if (add[i] == '\n')
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (add[i] != '\0')
	{
		result[i] = add[i];
		if (add[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*ft_add(int fd, char *buff, char *add)
{
	int		byte;
	char	*temp;

	if (add == 0)
		add = ft_strdup("");
	byte = 1;
	while (!ft_strchr(add, '\n') && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (add == 0)
			add = ft_strdup("");
		if ((byte == -1) || (byte == 0 && add[0] == 0))
		{
			ft_free(&add);
			free(buff);
			return (0);
		}
		buff[byte] = '\0';
		temp = add;
		add = ft_strjoin(add, buff);
		free(temp);
	}
	free(buff);
	return (add);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*add;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buff == 0)
		return (ft_free(&add));
	add = ft_add(fd, buff, add);
	if (add == 0)
		return (ft_free(&add));
	line = ft_extract(add);
	if (line == 0)
		return (ft_free(&add));
	add = ft_save(add);
	return (line);
}


static char	**ft_free_one(char **word, size_t wordnum)
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
				return (ft_free_one(word, wordnum));
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
			return (ft_free_one(word, 0));
		word[0] = 0;
		return (word);
	}
	word = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (word == 0)
		return (ft_free_one(word, 0));
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


void here_doc_sub(char *argv)
{
	int file;
	char *line;

	unlink(".here_doc_tmp");
	file = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		ft_error();
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			ft_error();
		if (!ft_strncmp(argv, line, ft_strlen(argv)) &&ft_strlen(argv) == ft_strlen(line) - 1)
			break;
		write(file, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(file);
}


void here_doc(int argc, char **argv, t_file *file)
{
	
	here_doc_sub(argv[2]);
	file->infile = open(".here_doc_tmp", O_RDONLY);
	if (file->infile < 0)
	{
		ft_error();
	}
	file->outfile = open(argv[argc -1], O_RDWR | O_APPEND | O_CREAT, 0644);
	if (file->outfile < 0)
	{
		ft_error();
	}
	
}

int main(int argc, char **argv, char **envp)
{

	int i;
	t_file file;

	i = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{	
		here_doc(argc, argv, &file);
	}
	else
		file.infile = file_open(argv[1], 1);
    	file.outfile = file_open(argv[argc - 1], 2);

    if (argc >= 5)
    {
		//infile을 닫고 표준입력파일을 가리키도록 함
		dup2(file.infile, STDIN_FILENO);
		//outfile을 닫고 표준출력파일을 가리키도록 함
        dup2(file.outfile, STDOUT_FILENO);
		get_pipe(argv[2], envp);
		while (i < argc - 2)
		{
			get_pipe(argv[i], envp);
			i++;
		}
		get_cmd(argv[i], envp);
    }
	else
		write(1, "argc error\n", 10);
    return (0);
}