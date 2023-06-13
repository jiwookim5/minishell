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


void select_pivot(int size, t_stack *a, t_value *pivot)
{
    int max;
    int min;

    max = get_max_value(a->top, size);
    min = get_min_value(a->top, size);
    pivot->pivot_1 = (max + min) / 2;
    pivot->pivot_2 = pivot->pivot_1 / 2;
    printf("pivot_1 : %d\n", pivot->pivot_1);
    printf("pivot_2 : %d\n", pivot->pivot_2);
}

int	push_swap(t_stack *a, t_stack *b, int size)
{
	t_value	pivot;
	int		i;
	int		temp;
	
	t_node *ay;
	t_node *be;

	ay = a->top;
	be = b->top;

	i = 0;
	if (size < 4)
	{
		i += size_three(a, size, i, &pivot);
		return (0);
	}
	select_pivot(a->size, a, &pivot);
	temp = size;
	while (temp--)
	{
		i += move_from_a(a, b, &pivot);
	}
	push_swap(a, b, size - pivot.ra );
    print_result(a, b);

	// printf("ddddddddddd\n");
	// printf("a1 : %d\n", a->top->value);
	// printf("a2 : %d\n", a->top->next->value);
	// printf("a3 : %d\n", a->top->next->next->value);
	// printf("a4 : %d\n", a->top->next->next->next->value);

	// printf("b1 : %d\n", b->top->value);
	// printf("b2 : %d\n", b->top->next->value);
	// // printf("b3 : %d\n", b->top->next->next->value);

	// printf("return : %d\n", i);
	return(i);
}