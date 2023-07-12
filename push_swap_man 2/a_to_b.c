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

int	move_from_a(t_stack **a, t_stack **b, t_value *pivot, int *temp)
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
		if ((*b)->top->value > pivot->pivot_1)
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

void	t_value_zero(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

int	exceptional_cases(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
	{
		handle_under_three(a, b, A, size);
		return (0);
	}
	else if (size == 4)
	{
		handle_sort_four(a, b, A, 4);
		return (0);
	}
	else if (size == 5)
	{
		hanlde_sort_five(a, b, A, 5);
		return (0);
	}
	return (1);
}

void	a_to_b(t_stack **a, t_stack **b, int size, int *cnt)
{
	t_value	pivot;
	int		temp;

	if (exceptional_cases(a, b, size) == 0)
		return ;
	t_value_zero(&pivot);
	select_pivot(size, a, &pivot);
	temp = size;
	while (temp-- > 0)
		temp = move_from_a(a, b, &pivot, &temp);
	if (pivot.ra > pivot.rb)
		return_raa(a, b, &pivot, cnt);
	else
		return_rbb(a, b, &pivot, cnt);
	a_to_b(a, b, pivot.ra, cnt);
	b_to_a(a, b, pivot.rb, cnt);
	b_to_a(a, b, pivot.pb - pivot.rb, cnt);
}
