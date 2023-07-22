/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_under_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:51:48 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/12 22:16:49 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	size_two(t_stack **a, t_stack **b, int flag)
{
	if (flag == A)
	{
		if ((*a)->top->value > (*a)->top->next->value)
			sa(a);
	}
	else
	{
		if ((*b)->top->value < (*b)->top->next->value)
		{
			sb(b);
		}		
		pa(a, b);
		pa(a, b);
	}
}

void	handle_under_three(t_stack **a, t_stack **b, int flag, int size)
{
	if (size == 3)
	{
		if (flag == A)
			size_three_a(a, size);
		else
			size_three_b(a, b, size);
	}
	else if (size == 2)
		size_two(a, b, flag);
	else if (size == 1)
		if (flag == B)
			pa(a, b);
}
