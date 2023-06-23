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

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    while (current != NULL)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void print_result(t_stack *a, t_stack *b)
{
    printf("Final state:\n");
    printf("a stack: ");
    print_stack(a);
    printf("b stack: ");
    print_stack(b);
}

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

void assign_index(t_stack *a, int size)
{
	int i;
	int *aa;
	t_node *ptr;

	aa = (int *)malloc(size * sizeof(int));
	i = 0;
	ptr = a->top;
	while (ptr)
	{
		aa[i] = ptr->value;
		ptr = ptr->next;
		i++;
	}
	ft_sort_int_tab(aa, size);
	
	// i = 0;
	// while (aa[i])
	// {
	// 	printf("aa : %d\n", aa[i]);
	// 	i++;
	// }

	while (size)
	{
		ptr->index = 
	}
}

// pivot 다시 정하기
void select_pivot(int size, t_stack *a, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = a->top;
	assign_index(a, size);
	write(1, "fuck3\n", 6);
	//printf("index1 : %d\n", a->top->index);
	//printf("index2 : %d\n", a->top->next->index);
	//printf("index3 : %d\n", a->top->next->next->index);
	//printf("index4 : %d\n", a->top->next->next->next->index);
	//printf("index5 : %d\n", a->top->next->next->next->next->index);
	//printf("index6 : %d\n", a->top->next->next->next->next->next->index);
	first = (size / 3); // 10 - 3, 100 / 3 = 33
	second = (size - first); // 10 - 7, 100 - 33 = 67
	printf("first : %d\n", first);
	printf("second : %d\n", second);
	
	while (fa)
	{
		if (fa->index == first)
			pivot->pivot_1 = fa->value;
		if (fa->index == second)
			pivot->pivot_2 = fa->value;
		fa = fa->next;
	}
	printf("pivot1 : %d\n", pivot->pivot_1);
	printf("pivot2 : %d\n", pivot->pivot_2);
}

void	push_swap(t_stack *a, t_stack *b, int size)
{
	write(1, "push_swap\n" , 10);
	t_value	pivot;
	int		i;
	int		temp;
	
	i = 0;
	pivot.pivot_1 = 0;
	pivot.pivot_2 = 0;
	pivot.ra = 0;
	if (size <= 3)
	{
		i += size_three(a, size, i, &pivot);
		return ;
	}
	printf("cvccccc\n");
	select_pivot(size, a, &pivot);
		
	temp = size;
	while (temp--)
	{
		i += move_from_a(a, b, &pivot);
		print_result(a, b);
	}
	//printf("ra : %d\n", pivot.ra);
	// push_swap(a, b, pivot.ra);
    //print_result(a, b);

	// printf("ddddddddddd\n");
	// printf("a1 : %d\n", a->top->value);
	// printf("a2 : %d\n", a->top->next->value);
	// printf("a3 : %d\n", a->top->next->next->value);
	// printf("a4 : %d\n", a->top->next->next->next->value);

	// printf("b1 : %d\n", b->top->value);
	// printf("b2 : %d\n", b->top->next->value);
	// // printf("b3 : %d\n", b->top->next->next->value);

	// printf("return : %d\n", i);
}
