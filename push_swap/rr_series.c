/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_series.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:58:51 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/12 22:38:29 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_two(t_node **lst, t_node *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast_two(*lst)->next = new;
}

void	ra(t_stack **a, int i)
{
	t_node	*first;
	t_node	*second;

	if ((*a)->top->next && (*a)->top)
	{
		first = (*a)->top;
		second = (*a)->top->next;
		ft_lstadd_back_two(&((*a)->top), first);
		first->next = NULL;
		(*a)->top = second;
	}
	if (i != 1)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, int i)
{
	t_node	*first;
	t_node	*second;

	if ((*b)->top && ((*b)->top->next))
	{
		first = (*b)->top;
		second = (*b)->top->next;
		ft_lstadd_back_two (&((*b)->top), first);
		first->next = NULL;
		(*b)->top = second;
	}
	if (i != 1)
		write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 1);
	rb(b, 1);
	write (1, "rr\n", 3);
}
