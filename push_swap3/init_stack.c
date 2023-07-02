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

//스택을 초기화. 빈 스택을 만든다.
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

//노드를 초기화. 빈 노드를 만듬
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

//노드를 연결
void		connect_list(t_node **temp, t_node **node, t_stack **stack)
{
	//스택에 노드가 없는경우 해당 노드를 제일 위로 올림
	if (!*node)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	//노드가 있으면 연결
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

//스택안에 노드를 세팅 
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

//스택을 만듬
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
    //노드 제일 처음으로 이동
    while (node->prev)
        node = node->prev;
    // //printf("valude : %d\n", node->value);
    return (node);
}
