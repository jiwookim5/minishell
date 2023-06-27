/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:35:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/27 18:27:33 by jiwkim2          ###   ########seoul.kr  */
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
		rb(&a);
		i++;	
		pivot->rb++;
	}
	return (i);
}

void	b_to_a(t_stack *a, t_stack *b, int size, int *xx)
{
	t_value	pivot;
	int		i;
	int		temp;
	
	i = 0;
	t_value_zero(&pivot);
	if (size <= 3)
	{
		i += size_three(b, size, i, &pivot);
		// print_result(a, b);
		return ;
	}
	select_pivot(size, b, &pivot);
		
	temp = size;
	while (temp--)
	{//e
		i += move_from_b(a, b, &pivot);
		// print_result(a, b);
	}
	a_to_b(a, b, pivot.pa - pivot.ra, xx);
	//printf("ra : %d\n", pivot.ra);
	// printf("ra : %d\n", pivot.ra);
		a_to_b(a, b, pivot.ra, xx);
		printf("pb : %d\n", pivot.pb);
	b_to_a(a, b, pivot.rb, xx);
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