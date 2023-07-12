/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_pivot_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:35:53 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/12 21:36:27 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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