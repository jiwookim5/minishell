#include "minishell.h"

char	**g_envp = NULL;


void	prompt(void)
{
	ft_putstr_fd("minishell-", STDERR_FILENO);
	ft_putstr_fd(VERSION, STDERR_FILENO);
	ft_putstr_fd("$ ", STDERR_FILENO);
}

int		minishell(void)
{
	t_list	*cmd_list;
	char	*line;

	line = NULL;
	while (1)
	{
		prompt();
		get_next_line(0, &line);
		if (cmd_list = parsing_first(line))
		{
			controller(cmd_list);
		}
		free(line);
	}
}

int		main(int argc, char **argv, char **envv)
{
	(void)argc;
	(void)argv;
	minishell();
}

