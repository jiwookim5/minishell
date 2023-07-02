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

void print_stack(t_stack **stack)
{
    t_node *current = (*stack)->top;
    while (current != NULL)
    {
        //printf("%d ", current->value);
        current = current->next;
    }
    //printf("\n");
}

void print_result(t_stack **a, t_stack **b)
{
    //printf("Final state:\n");
    //printf("a stack: ");
    print_stack(a);
    //printf("b stack: ");
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
		printf("ptr -> value : %d\n", ptr->value);
        ptr = ptr->next;
  
		i++;
    }
    ft_sort_int_tab(aa, size);

	//printf("size : %d\n", size);
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
				//printf("ptr->index : %d\n" , ptr->index);
				break;
            }
			compare_ptr = compare_ptr->next;
			i++;
        }
		//printf("aa[%d] : %d\n", i ,aa[i]);
        ptr = ptr->next;
    }
	free(aa);

}

// pivot 다시 정하기
void select_pivot(int size, t_stack **a, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = (*a)->top;
	assign_index(a, size);
	// first = 0;
	// second = 0;
	////printf("index1 : %d\n", a->top->index);
	////printf("index2 : %d\n", a->top->next->index);
	////printf("index3 : %d\n", a->top->next->next->index);
	////printf("index4 : %d\n", a->top->next->next->next->index);
	////printf("index5 : %d\n", a->top->next->next->next->next->index);
	////printf("index6 : %d\n", a->top->next->next->next->next->next->index);
	first = (size / 3 + 1);
	second = (size - first +1);
	//printf("size : %d\n", size);
	//heck_list(a, b);
	printf("first : %d second : %d \n", first, second);
	printf(" fa->value : %d\n", fa->value);
	while (fa)
	{
		if (fa->index == first)
			pivot->pivot_1 = fa->value;
		if (fa->index == second)
			pivot->pivot_2 = fa->value;
		fa = fa->next;
	}
	printf("pivot1 : %d pivot2 : %d\n", pivot->pivot_1, pivot->pivot_2);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int	cnt;
	cnt = 0;
	// if (a->size == 5)
	// {
	// 	//printf("fuck\n");
	// 	handle_arg_five(a, b);
	// }
	// else
	a_to_b(a, b, (*a)->size, &cnt);
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
		// //printf("size : %d\n", size);
		////printf("dddddddddd\n");
		handle_under_three(a, b, A, size);
		return (0);
	}
	// else if (size == 5)
	// {////printf("dddddddddd\n");
	// 	hanlde_sort_five(a, b, A, 5);
	// 	////printf("dddddddddd\n");
	// 	return (0);
		
	// }
	//else
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
			rrb(b);
	}
	else
	{
		rrd = pivot->rb;
		while (rrd--)
			rrb(b);
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
			rra(a);
	}
	else
	{
		while (rrd--)
			rrb(b);
	}
}

void	a_to_b(t_stack **a, t_stack **b, int size, int *cnt)
{
	printf("a_to_b\n");
	t_value	pivot;
	int		temp;
	
	//3개이하 이거나 5개일 때 
	//check_list(a,b);
	if (exceptional_cases(a, b, size) == 0)
		return ;
	////printf("fuck\n");
	t_value_zero(&pivot);
	select_pivot(size, a, &pivot);
	temp = size;
	while (temp--)
	{
		//check_list(a, b);
		move_from_a(a, b, &pivot);
		//print_result(a, b);
	}
	
	// //printf("dddddddddddddddd\n");
	////printf("ra : %d\n", pivot.ra);

	////printf("ra : %d\n", pivot.ra);
	
	// int turn = pivot.rb;
	// while (turn-- )
	// {
	// 	rrb(b);
	// 	//printf("rb : %d\n", pivot.rb);
	
	// }
	// check_list(a,b);
	if (pivot.ra > pivot.rb)
		return_raa(a, b, &pivot, cnt);
	else
	{
		return_rbb(a, b, &pivot, cnt);
	}
	a_to_b(a, b, pivot.ra, cnt);


	//printf("rb : %d\n", pivot.rb);
		// //printf("xx : %d\n");
	b_to_a(a, b, pivot.rb, cnt);

	b_to_a(a, b, pivot.pb - pivot.rb, cnt);
    	//print_result(a, b);

	// //printf("ddddddddddd\n");
	// //printf("a1 : %d\n", a->top->value);
	// //printf("a2 : %d\n", a->top->next->value);
	// //printf("a3 : %d\n", a->top->next->next->value);
	// //printf("a4 : %d\n", a->top->next->next->next->value);

	// //printf("b1 : %d\n", b->top->value);
	// //printf("b2 : %d\n", b->top->next->value);
	// // //printf("b3 : %d\n", b->top->next->next->value);

	// //printf("return : %d\n", i);
	// while(1)
	// {
		
	// }
}
