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

void	move_from_a(t_stack **a, t_stack **b, t_value *pivot)
{
	//pivot1 == 1 pivot2 == 4
	if ((*a)->top->value >= pivot->pivot_2)
	{
		printf("xccccccxcxccxccccx\n");
		ra(a);
		pivot->ra++;
	}
	else
	{
		printf("xccccccxcxccxccccx\n");
		printf("xccccccxcxccxccccx\n");
		pb(a, b);
		pivot->pb++;
		if ((*b)->top->value > pivot->pivot_1)
		{
			// print_result(a, b);
			rb(b);
			pivot->rb++;
			// print_result(a, b);
		}
	}
	// print_result(a, b);
}

void	top_value_min(t_stack **a, int max)
{
	if ((*a)->size == 3)
	{
		if ((*a)->top->next->value == max)
		{
			rra(a);
			sa(a);
		}
	}
	else
		if ((*a)->top->next->value == max)
		{
			// rra(a);
			// sa(a);
			// rra(a);
		return;
		}
}

void	top_next_value_min(t_stack **a, int max)
{
	if ((*a)->size == 3)
	{
		if ((*a)->bottom->value == max)
			sa(a);
		else
			ra(a);
	}
	else
		sa(a);
		if ((*a)->top->next->value == max)
		{
			// ra(a);
			// sa(a);
			// rra(a);
			return;
		}
}

void	top_next_next_value_min(t_stack **a, int max)
{
	// printf("a->size: %d\n", a->size);
	if ((*a)->size == 3)
	{
		if ((*a)->top->value == max)
			sa(a);
		printf("sdfjkldshgfkl \n");
		rra(a);
	}
	else
		{
		// if ((*a)->top->value == max)
		// 	sa(a);
		// ra(a);
		// sa(a);
		// rra(a);
		// sa(a);
		return;
		}
}

void	size_two(t_stack **a, t_stack **b, int flag)
{

	if (flag == A)
	{
		if ((*a)->top->value > (*a)->top->next->value)
			sa(a);
	}
	else
	{
		// printf("dddddd\n");
		// printf("b->top : %d, b->top->next : %d\n", (*b)->top->value, (*b)->top->next->value);

		if ((*b)->top->value < (*b)->top->next->value)
			{
				// printf("dddddd\n");
				sb(b);
			}		
		pa(a, b);
		pa(a, b);
	}
}

void	size_three_a(t_stack **a, int size)
{
	int	min;
	int	max;
	
	min = get_min_value((*a)->top, size);
	max = get_max_value((*a)->top, size);
	if ((*a)->top->value == min)
		top_value_min(a, max);
	else if ((*a)->top->next->value == min)
		top_next_value_min(a, max);
	else if ((*a)->top->next->next->value == min)
	{
		top_next_next_value_min(a, max);
	}

}