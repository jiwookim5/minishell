/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:54:50 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/12 18:54:50 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    get_max_value(t_node *node, int size)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

int		get_min_value(t_node *node, int size)
{
	int min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}


void select_pivot(int size, t_stack *a, t_value *pivot)
{
    int max;
    int min;

    max = get_max_value(a->top, size);
    min = get_min_value(a->top, size);
    pivot->pivot_1 = (max + min) / 2;
    pivot->pivot_2 = pivot->pivot_1 / 2;
    printf("pivot_1 : %d\n", pivot->pivot_1);
    printf("pivot_2 : %d\n", pivot->pivot_2);
}

void	push_swap(t_stack *a, t_stack *b)
{
	t_value	pivot;

	select_pivot(a->size, a, &pivot);
	move_from_a(a->size, a, b, &pivot);
}