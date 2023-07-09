/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 23:16:24 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/09 23:59:51 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_values_four(int value[])
{
	int	i;
	int	j;
	int	tmp;

	i = 3;
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
	return (value[0]);
}

int			get_first_value(t_node *node)
{
	int i;
	int value[4];

	i = 0;
	while(i < 4)
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
	return (sort_values_four(value));
}


void		handle_arg_four(t_stack **a, t_stack **b)
{
	int first;
	int pbb;

	pbb = 0;
	first = get_first_value((*a)->top);
	while (1)
	{
		if ((*a)->top->value == first)
		{
			pb(a, b);
			pbb++;
			(*a)->size--;
		}
		else
			ra(a, 2);
		if (pbb == 1)
			break;
	}
	size_three_a(a, 3);
	pa(a, b);
}

void	sort_four_a(int size, t_stack **a, t_stack **b)
{
	int	first;
	int push;
	int	rotate;

	push = 0;
	rotate = 0;
	first = get_first_value((*a)->top);
	while (size)
	{
		if ((*a)->top->value == first)
		{
			pb(a, b);
			push++;
		}
		else
		{
			ra(a, 2);
			rotate++;
		}
		if (push == 1)
			break;
		size--;
	}
	while (rotate--)
		rra(a, 2);
}

void	sort_four_b(int size, t_stack **a, t_stack **b)
{
	int	first;
	int push;
	int	rotate;

	push = 0;
	rotate = 0;
	first = get_first_value((*b)->top);
	while (size)
	{
		if ((*b)->top->value == first)
		{
			pa(a, b);
			push++;
		}
		else
		{
			rb(b, 2);
			rotate++;
		}
		if (push == 1)
			break;
		size--;
	}
	while (rotate--)
		rrb(b, 2);
}

void		handle_sort_four(t_stack **a, t_stack **b, int flag, int size)
{
	if (flag == A)
		sort_four_a(size, a, b);
	else
		sort_four_b(size, a, b);
	size_three_a(a, 3);
	if (flag == A)
		pa(a, b);
	else
		pb(a, b);
}