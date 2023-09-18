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



// void parsing_second(t_list *node, char **env)
// {
//     t_list *crr;
//     t_cmd *cmd;

//     cmd = NULL;

//     crr = node->next;
//     while (crr != NULL)
//     {
//         cmd = crr->content;
//         if (cmd->program[0])
//         {
//             printf("Sdafa31241234s\n");
//             ft_change(cmd->program, env);
//             printf("Sdafa312423412342341234s\n");

//         }
//         crr = crr->next;
//     }
    
//     // 처리된 프로그램 출력
//     int i = 0;
//     while (cmd->program[i] != NULL)
//     {
//         printf("program[%d]: %s\n", i, cmd->program[i]);
//         i++;
//     }
    
//     // 모든 프로그램에 대해 따옴표 및 환경 변수 처리
//     i = 0;
//     while (cmd->program[i] != NULL)
//     {
//         remove_quotes(cmd->program[i]);
//         i++;
//     }
// }