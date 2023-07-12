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

int	move_from_a(t_stack **a, t_stack **b, t_value *pivot , int *temp)
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
		handle_sort_five(a, b, A, 5);
		return (0);
	}
		return (1);
}

void	return_rbb(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
{
	int	rrd;
	int	rem;

	rrd = pivot->ra;
	rem = pivot->rb - rrd;
	if ((*cnt) > 0)
	{
		while (rrd--)
		{
			rrr(a, b);
		}
		while (rem--)
			rrb(b, 2);
	}
	else
	{
		rrd = pivot->rb;
		while (rrd--)
			rrb(b, 2);
	}
}


void	return_raa(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
{
	int	rrd;
	int	rem;

	rrd = pivot->rb;
	rem = pivot->ra - rrd;
	if ((*cnt) > 0)
	{
		while (rrd--)
			rrr(a, b);
		while (rem--)
			rra(a, 2);
	}
	else
	{
		while (rrd--)
			rrb(b, 2);
	}
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
