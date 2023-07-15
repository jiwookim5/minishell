/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:35:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/02 00:01:44 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_b_sub(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
	if ((*a)->top->value < pivot->pivot_2)
	{
		if ((*b)->top->value <= pivot->pivot_1)
		{
			if (*temp -1 == -1)
			{
				ra(a, 2);
				pivot->ra++;
				return (*temp);
			}
			rr (a, b);
			pivot->ra++;
			pivot->rb++;
			*temp = *temp - 1;
			return (*temp);
		}
		ra(a, 2);
		pivot->ra++;
	}
	return (*temp);
}

int	move_from_b(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
	int	i;

	if ((*b)->top->value <= pivot->pivot_1)
	{
		rb(b, 2);
		pivot->rb++;
	}
	else
	{
		pa(a, b);
		pivot->pa++;
		i = move_b_sub(a, b, pivot, temp);
	}
	return (*temp);
}

int	exceptional_cases_b(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
	{
		handle_under_three(a, b, B, size);
		return (0);
	}
	return (1);
}

void	b_to_a(t_stack **a, t_stack **b, int size, int *cnt)
{
	t_value	pivot;
	int		temp;

	(*cnt)++;
	if (size <= 3)
	{
		exceptional_cases_b(a, b, size);
		return ;
	}
	t_value_zero(&pivot);
	select_pivot_b(size, b, &pivot);
	temp = size;
	while (temp-- > 0)
		temp = move_from_b(a, b, &pivot, &temp);
	a_to_b(a, b, pivot.pa - pivot.ra, cnt);
	if (pivot.ra > pivot.rb)
		return_ra(a, b, &pivot);
	else
		return_rb(a, b, &pivot);
	a_to_b(a, b, pivot.ra, cnt);
	b_to_a(a, b, pivot.rb, cnt);
}
