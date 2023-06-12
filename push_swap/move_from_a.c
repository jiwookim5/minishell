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

void move_from_a(int size, t_stack *a, t_stack *b, t_value *pivot)
{
	int i;
	
	i = 0;
	while (a->top >= pivot->pivot_1)
	{
		ra(&a);
		i++;
		a->top = a->top->next;
	}
	while (a->top < pivot->pivot_1)
	{
		pb(&a, &b);
		i++;
		
	}
}