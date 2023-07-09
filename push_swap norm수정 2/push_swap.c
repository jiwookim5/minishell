/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:54:50 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/12 18:54:50 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    get_max_value(t_node *node, int size)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

int		get_min_value(t_node *node, int size)
{
	int min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}
void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	temp;

	a = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (tab[a] > tab[b])
			{
				temp = tab[a];
				tab[a] = tab[b];
				tab[b] = temp;
			}
			b++;
		}
		a++;
	}
}

void assign_index(t_stack **a, int size)
{
    int i;
    int *aa;
    t_node *ptr;
	t_node *compare_ptr;

    aa = (int *)malloc(size * sizeof(int));
    i = 0;
    ptr = (*a)->top;
    while (ptr && i < size)
    {
		ptr->index = 1;
        aa[i] = ptr->value;
        ptr = ptr->next;
  
		i++;
    }
    ft_sort_int_tab(aa, size);

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
				break;
            }
			compare_ptr = compare_ptr->next;
			i++;
		}
        ptr = ptr->next;
    }
	free(aa);

}

void select_pivot(int size, t_stack **a, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = (*a)->top;
	assign_index(a, size);
	first = (size / 3 + 1);
	second = (size - first +1);
	while (fa)
	{
		if (fa->index == first)
			pivot->pivot_1 = fa->value;
		if (fa->index == second)
			pivot->pivot_2 = fa->value;
		fa = fa->next;
	}
}

int	move_ones(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
if ((*a)->top->value >= pivot->pivot_2)
	{
		ra(a, 2);
		pivot->ra++;
	}
	else
	{
		pb(a, b);
		pivot->pb++;
		if ((*b)->top->value < pivot->pivot_1)
		{
			if ((*a)->top->value >= pivot->pivot_2)
			{
				if (*temp - 1 == -1)
				{
					rb(b, 2);
					pivot->rb++;
					return (*temp);
				}
				rr (a, b);
				pivot->rb++;
				pivot->ra++;
				*temp = *temp - 1;
				return (*temp);
			}
			rb(b, 2);
			pivot->rb++;
		}
	}
	return (*temp);
}

void	sort_algorithm(t_stack **a, t_stack **b, int size, t_value *pivot)
{
	int temp;

	if (exceptional_cases(a, b, size) == 0)
		return ;
	select_pivot(size, a, pivot);
	temp = size;
	while (temp-- > 0)
		temp = move_ones(a, b, pivot, &temp);
}


void	push_swap(t_stack **a, t_stack **b)
{
	int	cnt;
	t_value pivot;

	cnt = 0;
	if (is_sorted(a) == 1)
		return ;
	if ((*a)->size == 4)
		handle_arg_four(a, b);
	if ((*a)->size == 5)
		handle_arg_five(a, b);
	t_value_zero(&pivot);
	if (!(is_sorted(a)))
		sort_algorithm(a, b, (*a)->size, &pivot);
	a_to_b(a, b, pivot.ra, &cnt);
	b_to_a(a, b, pivot.pb - pivot.rb, &cnt);
	b_to_a(a, b, pivot.rb, &cnt);
}

void	t_value_zero(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}


int	exceptional_cases(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
	{
		handle_under_three(a, b, A, size);
		return (0);
	}
	else if (size == 4)
	{
		handle_sort_four(a, b, A, 4);
		return (0);
	}
	else if (size == 5)
	{
		handle_sort_five(a, b, A, 5);
		return (0);
	}
		return (1);
}

void	return_rbb(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
{
	int	rrd;
	int	rem;

	rrd = pivot->ra;
	rem = pivot->rb - rrd;
	if ((*cnt) > 0)
	{
		while (rrd--)
		{
			rrr(a, b);
		}
		while (rem--)
			rrb(b, 2);
	}
	else
	{
		rrd = pivot->rb;
		while (rrd--)
			rrb(b, 2);
	}
}


void	return_raa(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
{
	int	rrd;
	int	rem;

	rrd = pivot->rb;
	rem = pivot->ra - rrd;
	if ((*cnt) > 0)
	{
		while (rrd--)
			rrr(a, b);
		while (rem--)
			rra(a, 2);
	}
	else
	{
		while (rrd--)
			rrb(b, 2);
	}
}

void	a_to_b(t_stack **a, t_stack **b, int size, int *cnt)
{
	t_value	pivot;
	int		temp;
	
	if (exceptional_cases(a, b, size) == 0)
		return ;
	t_value_zero(&pivot);
	select_pivot(size, a, &pivot);
	temp = size;
	while (temp-- > 0)
		temp = move_from_a(a, b, &pivot, &temp);
	
	if (pivot.ra > pivot.rb)
		return_raa(a, b, &pivot, cnt);
	else
		return_rbb(a, b, &pivot, cnt);
	a_to_b(a, b, pivot.ra, cnt);


	b_to_a(a, b, pivot.rb, cnt);

	b_to_a(a, b, pivot.pb - pivot.rb, cnt);
}
