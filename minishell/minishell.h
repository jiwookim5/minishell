#ifndef MINISHELL
# define MINISHELL

# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <unistd.h>


typedef	struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

#endif