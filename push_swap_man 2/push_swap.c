/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:29:13 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/12 22:31:43 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_arg_four(t_stack **a, t_stack **b)
{
	int	first;
	int	pbb;

	pbb = 0;
	first = get_first_value((*a)->top);
	while (1)
	{
		if ((*a)->top->value == first)
		{
			pb(a, b);
			pbb++;
			(*a)->size--;
		}
		else
			ra(a, 2);
		if (pbb == 1)
			break ;
	}
	size_three_a(a, 3);
	pa(a, b);
}

void	handle_arg_five(t_stack **a, t_stack **b)
{
	int	pbb;
	int	mid;

	pbb = 0;
	mid = get_mid_value_five((*a)->top);
	while (1)
	{
		if ((*a)->top->value < mid)
		{
			pb(a, b);
			pbb++;
			(*a)->size--;
		}
		else
			ra(a, 2);
		if (pbb == 2)
			break ;
	}
	size_three_a(a, 3);
	size_two(a, b, B);
}

int	move_ones(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
	if ((*a)->top->value >= pivot->pivot_2)
	{
		ra(a, 2);
		pivot->ra++;
	}
	else
	{
		pb(a, b);
		pivot->pb++;
		if ((*b)->top->value < pivot->pivot_1)
		{
			if ((*a)->top->value >= pivot->pivot_2)
			{
				if (*temp - 1 == -1)
				{
					rb(b, 2);
					pivot->rb++;
					return (*temp);
				}
				rr (a, b);
				pivot->rb++;
				pivot->ra++;
				*temp = *temp - 1;
				return (*temp);
			}
			rb(b, 2);
			pivot->rb++;
		}
	}
	return (*temp);
}

void	sort_algorithm(t_stack **a, t_stack **b, int size, t_value *pivot)
{
	int	temp;

	if (exceptional_cases(a, b, size) == 0)
		return ;
	select_pivot(size, a, pivot);
	temp = size;
	while (temp-- > 0)
		temp = move_ones(a, b, pivot, &temp);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		cnt;
	t_value	pivot;

	cnt = 0;
	if (is_sorted(a) == 1)
		return ;
	if ((*a)->size == 4)
		handle_arg_four(a, b);
	if ((*a)->size == 5)
		handle_arg_five(a, b);
	t_value_zero(&pivot);
	if (!(is_sorted(a)))
		sort_algorithm(a, b, (*a)->size, &pivot);
	a_to_b(a, b, pivot.ra, &cnt);
	b_to_a(a, b, pivot.pb - pivot.rb, &cnt);
	b_to_a(a, b, pivot.rb, &cnt);
}
