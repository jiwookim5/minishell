/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_least_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 22:19:37 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/10 00:00:28 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_values(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 4;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (value[j] > value[j + 1])
			{
				tmp = value[j + 1];
				value[j + 1] = value[j];
				value[j] = tmp;
			}
			j++;
		}
		i--;
	}
	return (value[2]);
}

int			get_mid_value_five(t_node *node)
{
	int	i;
	int	value[5];

	i = 0;
	while (i < 5)
	{
		value[i] = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
		i++;
	}
	while (node->prev)
		node = node->prev;
	return (sort_values(value));
}

void		handle_arg_five(t_stack **a, t_stack **b)
{
	int	pbb;
	int	mid;

	pbb = 0;
	mid = get_mid_value_five((*a)->top);
	while (1)
	{
		if ((*a)->top->value < mid)
		{
			pb(a, b);
			pbb++;
			(*a)->size--;
		}
		else
			ra(a, 2);
		if (pbb == 2)
			break ;
	}
	size_three_a(a, 3);
	size_two(a, b, B);
}

void	sort_five_a(int size, t_stack **a, t_stack **b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value_five((*a)->top);
	while (size)
	{
		if ((*a)->top->value < mid)
		{
			pb(a, b);
			push++;
		}
		else
		{
			ra(a, 2);
			rotate++;
		}
		if (push == 2)
			break ;
		size--;
	}
	while (rotate--)
		rra(a, 2);
}

void	sort_five_b(int size, t_stack **a, t_stack **b)
{
	int	mid;
	int	push;
	int	rotate;

	push = 0;
	rotate = 0;
	mid = get_mid_value_five((*b)->top);
	while (size)
	{
		if ((*b)->top->value >= mid)
		{
			pa(a, b);
			push++;
		}
		else
		{
			rb(b, 2);
			rotate++;
		}
		if (push == 3)
			break ;
		size--;
	}
	while (rotate--)
		rrb(b, 2);
}

