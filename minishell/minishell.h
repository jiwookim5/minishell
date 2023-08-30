#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>


typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct	s_parsing
{
	int		p_i;
	int		i;
	int		j;
	char	quote;
	t_list	*head;
}				t_parsing;


int		main(int argc, char **argv);
int		minishell(void);
void	prompt(void);

#endif