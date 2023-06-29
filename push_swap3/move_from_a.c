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

void	move_from_a(t_stack *a, t_stack *b, t_value *pivot)
{
	if (a->top->value > pivot->pivot_2)
	{
		ra(&a);
		pivot->ra++;
	}
	else
	{
		pb(&a, &b);	
		pivot->pb++;
		if (b->top->value > pivot->pivot_1)
		{
			// print_result(a, b);
			rb(&b);
			pivot->rb++;
			// print_result(a, b);
		}
	}
	// print_result(a, b);
}

void	top_value_min(t_stack *a, int max, int size)
{
	if (size == 3)
	{
		if (a->top->next->value == max)
		{
			rra(&a);
			sa(a);
		}
	}
	else
		return ;
}

void	top_next_value_min(t_stack *a, int max, int size)
{
	if (size == 3)
	{
		if (a->bottom->value == max)
			sa(a);
		else
			ra(&a);
	}
	else
		return ;
}

void	top_next_next_value_min(t_stack *a, int max, int size)
{
	// printf("a->size: %d\n", a->size);
	if (size == 3)
	{
		if (a->top->value == max)
			sa(a);
		rra(&a);
	}
	else
		return ;

}

void	size_two(t_stack *a, t_stack *b, int flag)
{
	if (flag == A)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	else
	{
		if (b->top->value < b->top->next->value)
			sb(b);
		pa(&a, &b);
		pa(&a, &b);
	}
}

void	size_three_a(t_stack *a, int size)
{
	int	min;
	int	max;
	
	min = get_min_value(a->top, size);
	max = get_max_value(a->top, size);
	if (a->top->value == min)
		top_value_min(a, max, size);
	else if (a->top->next->value == min)
		top_next_value_min(a, max, size);
	else if (a->top->next->next->value == min)
	{
		top_next_next_value_min(a, max, size);
	}

}