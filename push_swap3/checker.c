/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:30:59 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/05 16:30:59 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack **a)
{
	t_node	*node;

	node = (*a)->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	//printf("node->value : %d, (*a)->bottom->value : %d\n", node->value, (*a)->bottom->value);
	//if (node->value == (*a)->bottom->value)
		return (1);
	//else
		//return (0);
}

void	checker(t_stack **a, t_stack **b)
{
	printf("dddddddddd\n");
    if (is_sorted(a) && !(*b)->top)
		printf("OK\n");
    
	else
		printf("KO\n");
}