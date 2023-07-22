/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index_sub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:12:58 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/15 22:16:07 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index_sub(t_stack **a, int i, int *aa)
{
	t_node	*ptr;
	t_node	*compare_ptr;

	ptr = (*a)->top;
	while (ptr)
	{
		i = 0;
		compare_ptr = (*a)->top;
		while (compare_ptr)
		{
			if (ptr->value == aa[i])
			{
				ptr->index = i + 1;
				break ;
			}
			compare_ptr = compare_ptr->next;
			i++;
		}
		ptr = ptr->next;
	}
}

void	assign_index_b_sub(t_stack **b, int i, int *aa)
{
	t_node	*ptr;
	t_node	*compare_ptr;

	ptr = (*b)->top;
	while (ptr)
	{
		i = 0;
		compare_ptr = (*b)->top;
		while (compare_ptr)
		{
			if (ptr->value == aa[i])
			{
				ptr->index = i + 1;
				break ;
			}
			compare_ptr = compare_ptr->next;
			i++;
		}
		ptr = ptr->next;
	}
}
