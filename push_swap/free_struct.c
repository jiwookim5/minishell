/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:49:54 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/15 16:54:39 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_b(t_stack **b)
{
	t_node	*temp;
	t_node	*node;

	node = (*b)->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free (node);
		node = temp;
	}
	free(*b);
}

void	free_a(t_stack **a)
{
	t_node	*temp;
	t_node	*node;

	node = (*a)->top;
	while (node)
	{
		if (node->next)
			temp = node->next;
		else
			temp = NULL;
		free (node);
		node = temp;
	}
	free(*a);
}

void	free_st(t_stack **a, t_stack **b)
{
	free_a(a);
	free_b(b);
}
