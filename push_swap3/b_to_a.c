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

//pivot_1 = 4
//pivot_2 = 7
void	move_from_b(t_stack **a, t_stack **b, t_value *pivot)
{
	if ((*b)->top->value < pivot->pivot_1)
	{
		rb(b);
		pivot->rb++;
	}
	else
	{
		pa(a, b);
		pivot->pa++;
		if ((*a)->top->value < pivot->pivot_2)
		{
			printf("ddddd\n");
			ra(a);
			pivot->ra++;
			// print_result(a, b);
		}
	}
	// print_result(a, b);
}

void	top_value_min_b(t_stack **b, int max)

{
	if ((*b)->size == 3)
	{
		rb(b);
		printf("(*b) : %d, %d, %d\n", (*b)->top->value, (*b)->top->next->value, (*b)->top->next->next->value);
		if ((*b)->top->next->value == max)
		{
			sb(b);
		}
		printf("mmmmmmmmmmmmmmmmmmmmmmmm\n");
		printf("(*b) : %d, %d, %d\n", (*b)->top->value, (*b)->top->next->value, (*b)->top->next->next->value);
	}
	else
	{
		// sb(b);
		// rb(b);
		// sb(b);
		// rrb(b);
		// if ((*b)->top->next->value == max)
		// 	sb(b);
		return;
	}
}
// 1	3
// 2	1
// 3	2
void	top_next_value_min_b(t_stack **b, int max)
{
	if ((*b)->size == 3)
	{
		rrb(b);
		if ((*b)->top->next->value == max)
			sb(b);
	}
	else
	{
		// rb(b);
		// sb(b);
		// rrb(b);
		// if ((*b)->top->next->value == max)
		// 	sb(b);
		return;
	}
}

void	top_next_next_value_min_b(t_stack **b, int max)
{
	if ((*b)->size == 3)
	{
		if ((*b)->top->next->value == max)
			sb(b);
	}
	else
		return ;
}

// int	check_sorted(t_node *tmp, int cnt, int stack)
// {
// 	int	i;

// 	if (cnt == 1)
// 		return (1);
// 	i = 1;

// 	if (stack == A)
// 	{
// 		//exit(1);
// 		while (i++ < cnt && tmp->next)
// 		{
// 			if (tmp->value > tmp->next->value)
// 				return (0);
// 			tmp = tmp->next;
// 		}
// 	}
// 	else if (stack == B)
// 	{
// 		printf("cnt : %d", cnt);
// 		while (i < cnt && tmp->next)
// 		{
// 			if (tmp->value < tmp->next->value)
// 				return (0);
// 			tmp = tmp->next;
// 			i++;
// 		}
// 		printf("stop\n");
// 	}

// 	return (1);
// }

// void	three_only_b(t_stack **a_st, t_stack **stacks, int cnt)
// {
// 	int	a;
// 	int	b;
// 	int	c;

// 	// exit(1);

// 	//printf("b stack : %d", (*stacks)->top->value);
// 	if (cnt == 1 || check_sorted((*stacks)->top, cnt, B))
// 		return ;
// 	while (!(check_sorted((*stacks)->top, cnt, B)))
// 	{
// 		a = (*stacks)->top->value;
// 		b = (*stacks)->top->next->value;
// 		if (cnt == 3)
// 			c = (*stacks)->top->next->next->value;
// 		if (cnt == 2 || (a > b && b < c && a > c) || (a < b && b > c && a > c)
// 			|| (a < b && b < c && a < c))
// 		{
// 			sb(stacks);
// 			continue ;
// 		}
// 		// 6	7
// 		// 5	6
// 		// 7	5
// 		if (a < b && b > c)
// 			rb(stacks);
// 		else
// 		{
// 			rrb(stacks);
// 			printf("fdsfsfsdbfjkdfbjksdbfjkbjkbdsjlbfjlsdbfjlsbdfdjlsf\n");
// 		}
// 		check_list(a_st, stacks);
// 	}
// 	pa(a_st, stacks);
// 	pa(a_st, stacks);
// 	pa(a_st, stacks);
// }

void	size_three_b(t_stack **a, t_stack **b, int size)
{
	int	min;
	int	max;
	
	check_list(a,b);
	min = get_min_value((*b)->top, size); // 1
	max = get_max_value((*b)->top, size); // 4
	printf("min : %d , max : %d\n", min, max);
	if ((*b)->top->value == min)
		top_value_min_b(b, max);
	else if ((*b)->top->next->value == min)
		top_next_value_min_b(b, max);
	else if ((*b)->top->next->next->value == min)
	{
		top_next_next_value_min_b(b, max);
	}
	pa(a, b);
	pa(a, b);
	pa(a, b);
}


// void	size_three_b(t_stack **b, int size)
// {
// 	int	min;
// 	int	max;

// 	min = get_min_value((*b)->top, size);
// 	max = get_max_value((*b)->top, size);
// 	if ((*b)->top->next->next->value == min)
// 		top_value_min(b, max, size);
// 	else if ((*b)->top->next->value == min)
// 		top_next_value_min(b, max, size);
// 	else if ((*b)->top->value== min)
// 	{
// 		top_next_next_value_min(b, max, size);
// 	}

// }


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

			write(1, "awd\n", 4);
			size_three_b(a, b, size);
			//size_three_b(b, size);
			printf("size : %d\n", size);
			// three_only_b(a, b, size);
			// while (size-- > 0)
			// {
			// 	// printf("xxxxxxxx\n");
			// 	pa(a, b);
				
			// }
		}
		
	}
	else if (size == 2)
	{
		size_two(a, b, flag);
		// printf("bbbbbbbbbbb\n");
	}
	else if (size == 1)
	{
		// printf("dnbu\n");
		if (flag == B)
		{
			printf("dnbu\n");
			//rrb(b);
			pa(a, b);
		}
		printf("done\n");
	}
}


int	exceptional_cases_b(t_stack **a, t_stack **b, int size)
{
	if (size <= 3)
	{
		// printf("size : %d\n", size);

		handle_under_three(a, b, B, size);
		return (0);
	}
	// else if (size == 5)
	// {
	// 	hanlde_sort_five(a, b, B, 5);
	// 	return (0);
	// // printf("dddddddddd\n");
	// }
	// else
	// 	return (1);
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
		rrb(b);
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
		rra(a);
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

void assign_index_b(t_stack **a, int size)
{
    int i;
    int *aa;
    t_node *ptr;

    aa = (int *)malloc(size * sizeof(int));
    i = 0;
    ptr = (*a)->top;
    while (ptr)
    {
        aa[i] = ptr->value;
        ptr = ptr->next;
        i++;
    }
    ft_sort_int_tab_b(aa, size);

    ptr = (*a)->top;
    while (ptr)
    {
		i = 0;
        while (i < size)
        {
            if (ptr->value == aa[i])
            {
                ptr->index = i + 1;
                break;
            }
			i++;
        }
		printf("index: %d\n", ptr->index);
        ptr = ptr->next;
    }
}

// pivot 다시 정하기
void select_pivot_b(int size, t_stack **b, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = (*b)->top;
	assign_index_b(b, size);
	// first = 0;
	// second = 0;
	//printf("index1 : %d\n", a->top->index);
	//printf("index2 : %d\n", a->top->next->index);
	//printf("index3 : %d\n", a->top->next->next->index);
	//printf("index4 : %d\n", a->top->next->next->next->index);
	//printf("index5 : %d\n", a->top->next->next->next->next->index);
	//printf("index6 : %d\n", a->top->next->next->next->next->next->index);
	first = (size / 3 + 1);
	second = (size - first +1);
	printf("first : %d second : %d \n", first, second);
	
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
void	b_to_a(t_stack **a, t_stack **b, int size, int *cnt)
{
	printf("b_to_a\n");
	t_value	pivot;
	int		temp;
	check_list(a, b);
	printf("size : %d\n", size);

	if (size <= 3)
	{
		exceptional_cases_b(a, b, size);
		check_list(a, b);
		return ;
	}

	t_value_zero(&pivot);
	select_pivot_b(size, b, &pivot);
		
	temp = size;
	while (temp--)
	{
		move_from_b(a, b, &pivot);
		// print_result(a, b);
		check_list(a, b);
	}
	//printf("ra : %d\n", pivot.ra);
		// printf("ra : %d\n", pivot.ra);
	a_to_b(a, b, pivot.pa - pivot.ra, cnt);
	// int turn = pivot.rb;
	// while (turn--)
	// {
	// 	rrb(b);
	// 	printf("rb : %d\n", pivot.rb);
	// }

	

	if (pivot.ra > pivot.rb)
		return_ra(a, b, &pivot);
	else
		return_rb(a, b, &pivot);
		// printf("pb : %d\n", pivot.pb);
		// printf("xx : %d\n");
		// b_to_a(a, b, pivot.pb);
	a_to_b(a, b,pivot.ra, cnt);
	b_to_a(a, b, pivot.rb, cnt);
	//a_to_b(a, b, pivot.ra);
	

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