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

void	top_value_min_a(t_stack **a, int max)
{
	if ((*a)->size == 3)
	{
		if ((*a)->top->next->value == max)
		{
			rra(a, 2);
			sa(a);
		}
	}
	else
		if ((*a)->top->next->value == max)
		{
			ra(a, 2);
			sa(a);
			rra(a, 2);
		return;
		}
}

void	top_next_value_min_a(t_stack **a, int max)
{
	if ((*a)->size == 3)
	{
		if ((*a)->bottom->value == max)
			sa(a);
		else
			ra(a, 2);
	}
	else
		sa(a);
		if ((*a)->top->next->value == max)
		{
			ra(a, 2);
			sa(a);
			rra(a, 2);
			return;
		}
}

void	top_next_next_value_min_a(t_stack **a, int max)
{
	if ((*a)->size == 3)
	{
		if ((*a)->top->value == max)
			sa(a);
		rra(a, 2);
	}
	else
		{
		if ((*a)->top->value == max)
			sa(a);
		ra(a, 2);
		sa(a);
		rra(a, 2);
		sa(a);
		return;
		}
}

void	size_three_a(t_stack **a, int size)
{
	int	min;
	int	max;
	
	min = get_min_value((*a)->top, size);
	max = get_max_value((*a)->top, size);
	if ((*a)->top->value == min)
		top_value_min_a(a, max);
	else if ((*a)->top->next->value == min)
		top_next_value_min_a(a, max);
	else if ((*a)->top->next->next->value == min)
		top_next_next_value_min_a(a, max);
}