/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:26:46 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/22 16:35:01 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->bottom = NULL;
	return (stack);
}

t_node	*node_init(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = 0;
	node->next = NULL;
	node->prev = NULL;
	node->index = 0;
	return (node);
}

void		connect_list(t_node **temp, t_node **node, t_stack **stack)
{
	if (!*node)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

void		node_set(char *argv, t_node **node, t_stack **a)
{
	int		i;
	char	**line;
	t_node	*temp;

	line = ft_split(argv, ' ');
	if (!line)
		ft_error();
	i = 0;
	while (line[i])
	{
		temp = node_init();
		temp->value = ft_atoi(line[i]);
		connect_list(&temp, node, a);
		(*a)->size++;
		i++;
	}
	int j = 0;
	while(line[j])
	{
		free(line[j]);
		j++;
	}
	free(line);
}

t_node *make_stack(int argc, char **argv, t_stack **a)
{
    int i;
    t_node *node;
	int j;

    i = 1;
    node = NULL;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
		{
			j++;
			if (argv[i][j] == '\0')
				ft_error();

		}
		node_set(argv[i], &node, a);
        i++;
	}
	if (!node->next)
		(*a)->bottom = node;
    while (node->prev)
        node = node->prev;
    return (node);
}
