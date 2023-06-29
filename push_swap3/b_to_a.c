/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:35:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/29 23:47:34 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_from_b(t_stack *a, t_stack *b, t_value *pivot)
{
	if (b->top->value > pivot->pivot_1)
	{
		rb(&b);
		pivot->rb++;
	}
	else
	{
		pa(&a, &b);	
		pivot->pa++;
		if (a->top->value > pivot->pivot_2)
		{
			// print_result(a, b);
			ra(&a);
			pivot->ra++;
			// print_result(a, b);
		}
	}
	// print_result(a, b);
}

void	top_value_min_b(t_stack *b, int max, int size)
{
	if (size == 3)
	{
		if (b->top->next->value == max)
		{
			rrb(&b);
			sb(b);
		}
	}
	else
		return ;
}

void	top_next_value_min_b(t_stack *b, int max, int size)
{
	if (size == 3)
	{
		if (b->bottom->value == max)
			sb(b);
		else
			rb(&b);
	}
	else
		return ;
}
void	top_next_next_value_min_b(t_stack *b, int max, int size)
{
	if (size == 3)
	{
		if (b->top->value == max)
			sb(b);
		rrb(&b);
	}
	else
		return ;
}


void	size_three_b(t_stack *b, int size)
{
	int	min;
	int	max;

	min = get_min_value(b->top, size);
	max = get_max_value(b->top, size);
	if (b->top->value == min)
		top_value_min(b, max, size);
	else if (b->top->next->value == min)
		top_next_value_min(b, max, size);
	else if (b->top->next->next->value == min)
	{
		top_next_next_value_min(b, max, size);
	}

}

int	exceptional_cases_b(t_stack *a, t_stack *b, int size)
{
	if (size <= 3)
	{
		// printf("size : %d\n", size);
		handle_under_three(a, b, B, size);
		return (0);
	}
	else if (size == 5)
	{
		hanlde_sort_five(a, b, B, 5);
		return (0);
	// printf("dddddddddd\n");
	}
	else
		return (1);
}

void	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_value	pivot;
	int		temp;
	
	if (!exceptional_cases(a, b, size))
		return ;
	t_value_zero(&pivot);
	select_pivot(size, b, &pivot);
		
	temp = size;
	while (temp--)
	{
		move_from_b(a, b, &pivot);
		// print_result(a, b);
	}
	//printf("ra : %d\n", pivot.ra);
		// printf("ra : %d\n", pivot.ra);
	a_to_b(a, b, pivot.ra);
	b_to_a(a, b, pivot.rb);
		// printf("pb : %d\n", pivot.pb);
		// printf("xx : %d\n");
		// b_to_a(a, b, pivot.pb);
    print_result(a, b);

	// printf("ddddddddddd\n");
	// printf("a1 : %d\n", a->top->value);
	// printf("a2 : %d\n", a->top->next->value);
	// printf("a3 : %d\n", a->top->next->next->value);
	// printf("a4 : %d\n", a->top->next->next->next->value);

	// printf("b1 : %d\n", b->top->value);
	// printf("b2 : %d\n", b->top->next->value);
	// // printf("b3 : %d\n", b->top->next->next->value);

	// printf("return : %d\n", i);
}