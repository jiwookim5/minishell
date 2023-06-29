/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:35:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/29 20:28:06 by jiwkim2          ###   ########seoul.kr  */
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
	}
}

void	top_value_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		if (b->top->next->value == max)
		{
			rrb(&b);
			sb(b);
		}
	}
	else
	{
		if (b->top->next->value == max)
		{
			rb(&b);
			sb(b);
			rrb(&b);
		}
	}
}

void	top_next_value_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		if (b->bottom->value == max)
			sb(b);
		else
			rb(&b);
	}
	else
	{
		sb(b);
		if (b->top->next->value == max)
		{
			rb(&b);
			sb(b);
			rrb(&b);
		}
	}
}

void	top_next_next_value_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		if (b->top->value == max)
			sb(b);
		rrb(&b);
	}
	else
	{
		if (b->top->value == max)
			sb(b);
		rb(&b);
		sb(b);
		rrb(&b);
		sb(b);
	}
}


void	size_three_b(t_stack *b, int size)
{
	int	min;
	int	max;

	min = get_min_value(b->top, size);
	max = get_max_value(b->top, size);
	if (b->top->value == min)
		top_value_min(b, max);
	else if (b->top->next->value == min)
		top_next_value_min(b, max);
	else if (b->top->next->next->value == min)
	{
		top_next_next_value_min(b, max);
	}

}

// void	sort_five_b(int size, t_stack *a, t_stack *b)
// {
// 	int	mid;
// 	int	push;
// 	int	rotate;

// 	push = 0;
// 	rotate = 0;
// 	mid = get_mid_value_five(b->top);
// 	while (size--)
// 	{
// 		if (b->top->value >= mid)
// 		{
// 			pa(&a, &b);
// 			push++;
// 		}
// 		else
// 		{
// 			rb(&b);
// 			rotate++;
// 		}
// 		if (push == 3)
// 			break ;
// 	}
// 	while (rotate--)
// 		rrb(&b);
// }

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