/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_series.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:59:58 by jiwkim2           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/07/15 16:57:26 by jiwkim2          ###   ########seoul.kr  */
=======
/*   Updated: 2023/07/12 22:00:49 by jiwkim2          ###   ########seoul.kr  */
>>>>>>> parent of 43a5dd7... dsfgnklsd
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
void	rra(t_stack **a, int i)
{
	t_node	*temp;
	t_node	*last_front;
	t_node	*stack;

	stack = (*a)->top;
	if (!(stack && stack->next))
		return ;
	temp = stack;
	while (temp->next)
	{
		last_front = temp;
		temp = temp->next;
=======
void rra(t_stack **a, int i)
{
    t_node   *temp;
	t_node   *last_front;
	t_node   *stack;

	stack = (*a)->top;
	if (!(stack && stack->next))
    	return ;
	temp = stack;
	while (temp->next)
	{
    	last_front = temp;
    	temp = temp->next;
>>>>>>> parent of 43a5dd7... dsfgnklsd
	}
	temp->next = stack;
	last_front->next = NULL;
	(*a)->top = temp;
	if (i != 1)
<<<<<<< HEAD
		write (1, "rra\n", 4);
=======
    	write(1, "rra\n", 4);
>>>>>>> parent of 43a5dd7... dsfgnklsd
}

void	rrb(t_stack **b, int i)
{
	t_node	*temp;
	t_node	*last_front;
	t_node	*stack;

<<<<<<< HEAD
	stack = (*b)->top;
	if (!(stack && stack->next))
		return ;
	temp = stack;
	while (temp->next)
	{
		last_front = temp;
		temp = temp->next;
	}
	temp->next = stack;
	last_front->next = NULL;
	(*b)->top = temp;
	if (i != 1)
		write (1, "rrb\n", 4);
=======
    stack = (*b)->top;
    if (!(stack && stack->next))
        return ;
    temp = stack;
    while (temp->next)
    {
        last_front = temp;
        temp = temp->next;
    }
    temp->next = stack;
    last_front->next = NULL;
    (*b)->top = temp;
    if (i != 1)
        write(1, "rrb\n", 4);
>>>>>>> parent of 43a5dd7... dsfgnklsd
}

void	rrr(t_stack **a, t_stack **b)
{
<<<<<<< HEAD
	rra (a, 1);
	rrb (b, 1);
	write (1, "rrr\n", 4);
=======
    rra(a, 1);
    rrb(b, 1);
    write(1, "rrr\n", 4);
>>>>>>> parent of 43a5dd7... dsfgnklsd
}
