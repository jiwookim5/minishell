/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:29:59 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/21 15:13:29 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sa(t_stack **a)
{
    t_node *temp;

    if ((*a)->top)
    {
        temp = (*a)->top;
        (*a)->top = (*a)->top->next;
        temp->next = (*a)->top->next;
        (*a)->top->next = temp;
        write(1, "sa\n", 3);
    }
    else
        ft_error();
}

void    sb(t_stack **b)
{
    t_node *temp;
    
    if ((*b)->top)
    {
        temp = (*b)->top;
        (*b)->top = (*b)->top->next;
        temp->next = (*b)->top->next;
        (*b)->top->next = temp;
        write(1, "sb\n", 3);
    }
    else
        ft_error();
}

void    ss(t_stack **a, t_stack **b)
{
    if ((*a)->top && (*b)->top)
    {
        sa(a);
        sb(b);
        write(1, "ss\n", 3);
    }
    else
        ft_error();
}

void	pa(t_stack **a, t_stack **b)
{
	t_node *temp;

    if ((*b)->top)
    {
        temp = (*b)->top->next;
        ft_lstadd_front_two(&((*a)->top), (*b)->top);
        (*b)->top = temp;
    }
    write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_node *temp;

    if ((*a)->top)
    {
        temp = (*a)->top->next;
        ft_lstadd_front_two(&((*b)->top), (*a)->top);
        (*a)->top = temp;
    }
    write(1, "pb\n", 3);
}
