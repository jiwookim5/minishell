/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 19:30:35 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/12 20:13:50 by jiwkim2          ###   ########seoul.kr  */
/*                                                                          */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_a(t_stack *a, t_stack *b, t_value *pivot)
{
	int i;

	i = 0;
	if (a->top->value >= pivot->pivot_1)
	{
		printf("ddddddd\n");
		ra(&a);
		i++;
		pivot->ra++;
	}
	else
	{
		pb(&a, &b);
		i++;	
	}
	return (i);
}

int	top_value_min(t_stack *a, int max, int i)
{
	if (a->top->next->value == max)
	{
		rra(&a);
		sa(a);
		i += 2;
	}
	return (i);
}

int	top_next_value_min(t_stack *a, int max, int i, t_value *pivot)
{
	if (a->top->next->next->value == max)
	{
		sa(a);
		i++;
	}
	else
	{
		ra(&a);
		pivot->ra++;
		i++;
	}
	return (i);
}

int	top_next_next_value_min(t_stack *a, int max, int i)
{

	if (a->top->value == max)
	{
		sa(a);
		i++;
	}
	rra(&a);
	i++;
	return (i);
}

int	size_three(t_stack *a, int size, int i, t_value *pivot)
{
	int	min;
	int	max;

	min = get_min_value(a->top, size);
	max = get_max_value(a->top, size);
	if (a->top->value == min)
		i = top_value_min(a, max, i);
	else if (a->top->next->value == min)
		i = top_next_value_min(a, max, i, pivot);
	else if (a->top->next->next->value == min)
		i = top_next_next_value_min(a, max, i);
	return (i);
}