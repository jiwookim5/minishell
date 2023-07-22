/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 22:01:17 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/12 22:26:48 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstlast_two(t_node *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front_two(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

void	pa(t_stack **a, t_stack **b)
{
	t_node	*temp;

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
	t_node	*temp;

	if ((*a)->top)
	{
		temp = (*a)->top->next;
		ft_lstadd_front_two(&((*b)->top), (*a)->top);
		(*a)->top = temp;
	}
	write (1, "pb\n", 3);
}
