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

int	move_from_b(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
	if ((*b)->top->value <= pivot->pivot_1)
	{
		rb(b, 2);
		pivot->rb++;
	}
	else
	{
		pa(a, b);
		pivot->pa++;
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
	else if (size == 4)
	{
		handle_sort_four(a, b, B, 4);
		return (0);
	}
	else if (size == 5)
	{
		handle_sort_five(a, b, B, 5);
		return (0);
	}
	return (1);
}

void	return_rb(t_stack **a, t_stack **b, t_value *pivot)
{
	int	rrd;
	int	rem;

	rrd = pivot->ra;
	rem = pivot->rb - rrd;
	while (rrd--)
		rrr(a,b);
	while (rem--)
		rrb(b, 2);
}


void	return_ra(t_stack **a, t_stack **b, t_value *pivot)
{
	int	rrd;
	int	rem;

	rrd = pivot->rb;
	rem = pivot->ra - rrd;
	while(rrd--)
		rrr(a,b);
	while(rem--)
	{
		rra(a, 2);
	}
}

void	b_to_a(t_stack **a, t_stack **b, int size, int *cnt)
{
	(*cnt)++;
	t_value	pivot;
	int		temp;
	
	if (size <= 3)
	{
		exceptional_cases_b(a, b, size);
		return ;
	}

	t_value_zero(&pivot);

	select_pivot_b(size,  b, &pivot);			
	temp = size;
	while (temp-- > 0)
		temp = move_from_b(a, b, &pivot, &temp);

	a_to_b(a, b, pivot.pa - pivot.ra, cnt);

	if (pivot.ra > pivot.rb)
		return_ra(a, b, &pivot);
	else
		return_rb(a, b, &pivot);

	a_to_b(a, b,pivot.ra, cnt);
	

	b_to_a(a, b, pivot.rb, cnt);
}