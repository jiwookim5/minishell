/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:35:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/27 21:32:15 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_b(t_stack *a, t_stack *b, t_value *pivot)
{
	int i;

	i = 0;
	if (b->top->value > pivot->pivot_2)
	{
		pa(&a, &b);
		i++;
		pivot->pa++;
	}
	else
	{
		rb(&b);
		i++;	
		pivot->rb++;
	}
	return (i);
}

int	top_value_min_b(t_stack *b, int max, int i)
{
	if (b->top->next == NULL)
		return (i);
	if (b->top->next->value == max)
	{
		rrb(&b);
		sb(b);
		i += 2;
	}
	return (i);
}

int	top_next_value_min_b(t_stack *b, int max, int i, t_value *pivot)
{
	if (b->top->next->next == NULL)
	{
		if(b->top->value > b->top->next->value)
		{
			sb(b);
			i++;
		}
		return(i);
	}
	if (b->top->next->next->value == max)
	{
		sb(b);
		i++;
	}
	else
	{
		printf("ddddd\n");
		rb(&b);
		pivot->rb++;
		i++;
	}
	return (i);
}

int	top_next_next_value_min_b(t_stack *b, int max, int i)
{
	if (b->top->value == max)
	{
		sb(b);
		i++;
	}
	rrb(&b);
	i++;
	return (i);
}

int	size_three_b(t_stack *b, int size, int i, t_value *pivot)
{
	int	min;
	int	max;

	min = get_min_value(b->top, size);
	max = get_max_value(b->top, size);
	if (b->top->value == min)
		i = top_value_min_b(b, max, i);
	else if (b->top->next->value == min)
		i = top_next_value_min_b(b, max, i, pivot);
	else if (b->top->next->next->value == min)
	{
		i = top_next_next_value_min_b(b, max, i);
	}
	return (i);
}

void	b_to_a(t_stack *a, t_stack *b, int size)
{
	printf("size : %d\n", size);
	t_value	pivot;
	int		i;
	int		temp;
	
	i = 0;
	t_value_zero(&pivot);
	if (size <= 3)
	{
		i += size_three_b(b, size, i, &pivot);
		// print_result(a, b);
		return ;
	}
	printf("fuck\n");
	select_pivot(size, b, &pivot);
	temp = size;
	while (temp--)
	{//e
		i += move_from_b(a, b, &pivot);
		// print_result(a, b);
	}
	a_to_b(a, b, pivot.pa - pivot.ra);
	//printf("ra : %d\n", pivot.ra);
	// printf("ra : %d\n", pivot.ra);
		a_to_b(a, b, pivot.ra);
		printf("pb : %d\n", pivot.pb);
		printf("rb : %d\n", pivot.rb);
	b_to_a(a, b, pivot.rb);
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