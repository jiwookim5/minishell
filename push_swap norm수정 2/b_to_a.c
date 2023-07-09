/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:35:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/02 00:01:44 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_from_b(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
	if ((*b)->top->value <= pivot->pivot_1)
	{
		rb(b, 2);
		pivot->rb++;
	}
	else
	{
		pa(a, b);
		pivot->pa++;
		if ((*a)->top->value < pivot->pivot_2)
		{
			if ((*b)->top->value <= pivot->pivot_1)
			{
				if (*temp -1 == -1)
				{
					ra(a, 2);
					pivot->ra++;
					return (*temp);
				}
				rr (a, b);
				pivot->ra++;
				pivot->rb++;
				*temp = *temp - 1;
				return (*temp);
			}
			ra(a, 2);
			pivot->ra++;
		}
	}
	return (*temp);
}

void	top_value_min_b(t_stack **b, int max)

{
	if ((*b)->size == 3)
	{
		rb(b,2);
		if ((*b)->top->next->value == max)
		{
			sb(b);
		}
	}
	else
	{
		sb(b);
		rb(b,2);
		sb(b);
		rrb(b, 2);
		if ((*b)->top->next->value == max)
			sb(b);
		return;
	}
}

void	top_next_value_min_b(t_stack **b, int max)
{
	if ((*b)->size == 3)
	{
		rrb(b, 2);
		if ((*b)->top->next->value == max)
			sb(b);
	}
	else
	{
		rb(b,2);
		sb(b);
		rrb(b, 2);
		if ((*b)->top->next->value == max)
			sb(b);
		return;
	}
}

void	top_next_next_value_min_b(t_stack **b, int max)
{
	
	if ((*b)->size <= 3)
	{

		if ((*b)->top->next->value == max)
			sb(b);
	}
	else
		return ;
}

void	size_three_b(t_stack **a, t_stack **b, int size)
{
	int	min;
	int	max;
	
	min = get_min_value((*b)->top, size);
	max = get_max_value((*b)->top, size);
	if ((*b)->top->value == min)
		top_value_min_b(b, max);
	else if ((*b)->top->next->value == min)
		top_next_value_min_b(b, max);
	else if ((*b)->top->next->next->value == min)
		top_next_next_value_min_b(b, max);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}

void	handle_under_three(t_stack **a, t_stack **b, int flag, int size)
{

	if (size == 3)
	{
		if (flag == A)
		{
			
			size_three_a(a, size);
			
		}
		else
		{
			size_three_b(a, b, size);
		}
		
	}
	else if (size == 2)
	{
		size_two(a, b, flag);
	}
	else if (size ==1)
	{
		if (flag == B)
		{
			pa(a, b);
		}
	}
}


int	exceptional_cases_b(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
	{
		handle_under_three(a, b, B, size);
		return (0);
	}
	else if (size == 4)
	{
		handle_sort_four(a, b, B, 4);
		return (0);
	}
	else if (size == 5)
	{
		handle_sort_five(a, b, B, 5);
		return (0);
	}
	return (1);
}

void	return_rb(t_stack **a, t_stack **b, t_value *pivot)
{
	int	rrd;
	int	rem;

	rrd = pivot->ra;
	rem = pivot->rb - rrd;
	while (rrd--)
		rrr(a,b);
	while (rem--)
		rrb(b, 2);
}


void	return_ra(t_stack **a, t_stack **b, t_value *pivot)
{
	int	rrd;
	int	rem;

	rrd = pivot->rb;
	rem = pivot->ra - rrd;
	while(rrd--)
		rrr(a,b);
	while(rem--)
	{
		rra(a, 2);
	}
}
void	ft_sort_int_tab_b(int *tab, int size)
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

void assign_index_b(t_stack **b, int size)
{
    int i;
    int *aa;
    t_node *ptr;
	t_node *compare_ptr;

    aa = (int *)malloc(size * sizeof(int));
    i = 0;
    ptr = (*b)->top;

    while (ptr && i < size)
    {
		ptr->index = 1;
        aa[i] = ptr->value;

        ptr = ptr->next;
        i++;
    }

    ft_sort_int_tab_b(aa, size);
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
                break;
            }
			compare_ptr = compare_ptr->next;
			i++;
        }
        ptr = ptr->next;
    }
	free(aa);
}

void select_pivot_b(int size, t_stack **b, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = (*b)->top;

	assign_index_b(b, size);
	first = (size / 3 + 1);
	second = (size - first +1);

	while (fa && size)
	{
		if (fa->index == first)
			pivot->pivot_1 = fa->value;
		if (fa->index == second)
			pivot->pivot_2 = fa->value;
		fa = fa->next;
		size--;
	}
}
void	b_to_a(t_stack **a, t_stack **b, int size, int *cnt)
{
	(*cnt)++;
	t_value	pivot;
	int		temp;
	
	if (size <= 3)
	{
		exceptional_cases_b(a, b, size);
		return ;
	}

	t_value_zero(&pivot);

	select_pivot_b(size,  b, &pivot);			
	temp = size;
	while (temp-- > 0)
		temp = move_from_b(a, b, &pivot, &temp);

	a_to_b(a, b, pivot.pa - pivot.ra, cnt);

	if (pivot.ra > pivot.rb)
		return_ra(a, b, &pivot);
	else
		return_rb(a, b, &pivot);

	a_to_b(a, b,pivot.ra, cnt);
	

	b_to_a(a, b, pivot.rb, cnt);
}