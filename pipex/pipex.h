/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:59:51 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/13 13:57:02 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_file	t_file;

struct s_file
{	
	int infile;
	int outfile;
};

int main(int argc, char **argv, char **envp);
void get_pipe(char *cmd, char **envp);
int file_open(char *argv, int i);
void ft_error(void);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char *ft_route(char *path);
int ft_str_chr(char *str, char c);
char *path_join(char *path, char *cmd);
char	*ft_str_dup (char *str, int n);
char *get_path(char *commend, char **envp);
void	get_cmd (char *cmd, char **envp);
char	**ft_free_one(char **word, size_t wordnum);
size_t	ft_word_count(char const *str, char charset);
char	**split(char **word, char const *str, char charset);
char	**ft_split(char const *s, char c);

//bonus
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
 void here_doc(int argc, char **argv, t_file *file);
 void here_doc_sub(char *argv);
 
 

# endif

// CC = cc
// CFLAGS = -Wall -Wextra -Werror
// NAME = pipex
// SRCS = pipex.c pipex_utils.c get_cmd.c ft_split.c
// SRCS_BONUS = bonus/bonus.c

// OBJS = $(SRCS:.c=.o)
// OBJSB = $(SRCS_BONUS:.c=.o)

// all: $(NAME)

// $(NAME): $(OBJS)
// 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

// bonus: $(OBJSB)
// 	make -C bonus
// 	cp bonus/bonus $(NAME)

// %.o : %.c
// 	$(CC) $(CFLAGS) -c -o $@ $<

// clean:
// 	rm -f $(OBJS)
// 	make -C bonus clean

// fclean: clean
// 	rm -f $(NAME)
// 	make -C bonus fclean

// re: fclean all

// .PHONY: clean fclean all re bonus