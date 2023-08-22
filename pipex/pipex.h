/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:59:51 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/22 20:54:16 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>

# define BUFFER_SIZE 42

typedef struct s_file	t_file;

struct s_file
{
	int	infile;
	int	outfile;
	int	j;
};

int		main(int argc, char **argv, char **envp);
void	get_pipe(char *cmd, char **envp);
int		file_open(char *argv, int i);
void	ft_error(void);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_str_chr(char *str, char c);
char	*path_join(char *path, char *cmd);
char	*ft_str_dup(char *str, int n);
char	*get_path(char *commend, char **envp, int i);
void	get_cmd(char *cmd, char **envp);
char	**ft_free_one(char **word, size_t wordnum);
size_t	ft_word_count(char const *str, char charset);
char	**split(char **word, char const *str, char charset);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_free(char **add);
char	*ft_save(char *add);
char	*ft_extract(char *add);
char	*ft_add(int fd, char *buff, char *add);
char	*get_next_line(int fd);
void	here_doc(int argc, char **argv, t_file *file);
void	here_doc_sub(char *argv);
char	*get_path_sub(char *path, char *c, char *path_cmd, char *commend);
void	file_zero(t_file *file);
int		ft_strcmp(const char *str1, const char *str2);

#endif
