/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:05:03 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/09/16 19:29:41 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

// # define PIPE 1
// # define SEMICOLON 0

// enum e_type
// {
// 	WORD,
	// REDIR_IN,
	// REDIR_OUT,
// 	HEREDOC,
// 	APPEND;
// };
// ls / < infile / -al / > outfile
// WORD / REDIR_IN / WORD / REDIR_OUT
// {"ls", "-al"}


typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_cmd
{
	int		flag;
	char	**program;
}				t_cmd;

//p_i parsing index, j = buff index, i = line index
typedef struct	s_parsing
{
	int		p_i;
	int		i;
	int		j;
	int		token_count;
	char	quote;
	char 	*buff;
	t_list	*head;
	t_cmd	*content;
}				t_parsing;


int		main(int argc, char **argv, char **env);
int		minishell(char **env);
void	prompt(void);

//libft
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
t_list	*ft_lstnew(void *content);
void	ft_bzero(void *s, size_t n);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif


// char *change_quote(char **program, char **env)
// {
//     int i = 0;
//     char *name;
//     char *value;

//     // program[i]에서 $ 문자를 만날 때까지 문자열을 복사합니다.
//     int j = 0;
//     while (program[i][j] != '\0' && program[i][j] != '$')
//     {
//         j++;
//     }
//     name = ft_strdup(program[i] + j);
//     // $ 문자가 있었다면 해당 문자열의 마지막 문자를 제거합니다.
//     if (j > 0)
//     {
//         name[j - 1] = '\0';
//     }

//     while (env[i])
//     {
//         if (ft_strncmp(env[i], name, ft_strlen(name)) == 0)
//         {
//             value = ft_strchr(env[i], '=');
//             if (value)
//             {
//                 free(name);
//                 return (ft_strdup(value + 1));
//             }
//         }
//         i++;
//     }
//     free(name);
//     return (NULL);
// }