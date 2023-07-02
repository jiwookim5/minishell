/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:21:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/23 14:30:05 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define A 1
# define B 2

typedef struct s_stack	t_stack;
typedef struct s_node	t_node;
typedef struct s_value	t_value;

t_node *make_stack(int argc, char **argv, t_stack **stack);
t_stack			*stack_init(void);
void	print_error(void);
t_node	*node_init(void);
char			**ft_split(char const *s, char c);
void	number_check(char *str);
void		node_set(char *argv, t_node **node, t_stack **a);
void		connect_list(t_node **temp, t_node **node, t_stack **stack);
int	main(int argc, char *argv[]);
long long	ft_atoi(char *str);
void	ft_error(void);
void	str_check(char *str);
int	chk_arg_length(char *arg);
void	same_check(t_node *a);
void	ft_lstadd_front_two(t_node **lst, t_node *new);
void    sa(t_stack **a);
void    sb(t_stack **b);
void    ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
t_node	*ft_lstlast_two(t_node *lst);
void	push_swap(t_stack **a, t_stack **b);
void	ft_lstadd_back_two(t_node **lst, t_node *new);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void	t_value_zero(t_value *var);

void select_pivot(int size, t_stack **stack, t_value *pivot);
int    get_max_value(t_node *node, int size);
int		get_min_value(t_node *node, int size);
void	size_three_a(t_stack **a, int size);


void	move_from_a(t_stack **a, t_stack **b, t_value *pivot);
void print_result(t_stack **a, t_stack **b);
void assign_index(t_stack **stack_a, int stack_size);
void	move_from_b(t_stack **a, t_stack **b, t_value *pivot);
void	b_to_a(t_stack **a, t_stack **b, int size, int *cnt);

void	top_next_value_min_b(t_stack **b, int max);
void	top_next_next_value_min_b(t_stack **b, int max);
void	size_three_b(t_stack **a, t_stack **b, int size);
void	top_value_min_b(t_stack **b, int max);
int	exceptional_cases(t_stack **a, t_stack **b, int size);
void		hanlde_sort_five(t_stack **a, t_stack **b, int flag, int size);
void	sort_five_a(int size, t_stack **a, t_stack **b);
void	sort_five_b(int size, t_stack **a, t_stack **b);
void		handle_arg_five(t_stack **a, t_stack **b);
int			get_mid_value_five(t_node *node);
int	sort_values(int value[]);
void	size_two(t_stack **a, t_stack **b, int flag);
void	top_next_next_value_min(t_stack **a, int max);
void	top_next_value_min(t_stack **a, int max);
void	top_value_min(t_stack **a, int max);
int	exceptional_cases_b(t_stack **a, t_stack **b, int size);
void	handle_under_three(t_stack **a, t_stack **b, int flag, int size);
void three_only_b(t_stack **a_st,t_stack **stacks, int cnt);
void	a_to_b(t_stack **a, t_stack **b, int size, int *cnt);
void	ft_sort_int_tab_b(int *tab, int size);
void assign_index_b(t_stack **a, int size);
void select_pivot_b(int size, t_stack **b, t_value *pivot);

struct	s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom; // 스택 가장 아래에 있는 노드 가리키는 포인터
};

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
	int index;
};

struct	s_value
{
    int pivot_1;
    int pivot_2;
	int ra;
	int rb;
	int pa;
	int	pb;

};

void check_list(t_stack **a, t_stack **b);
void	return_rb(t_stack **a, t_stack **b, t_value *pivot);
void	return_ra(t_stack **a, t_stack **b, t_value *pivot);
void	return_rbb(t_stack **a, t_stack **b, t_value *pivot, int *cnt);
void	return_raa(t_stack **a, t_stack **b, t_value *pivot, int *cnt);

#endif



// void check_list(t_stack **a, t_stack **b)
// {
// 	if (print_max == 3000)
// 		return; // exit(1);
// 	print_max++;
// 	printf("print_max_idx: %d\n", print_max);
// 	printf("\n");
// 	int cnt = 1;
// 	printf("============\t============\n");

// 	t_node *aa;
// 	t_node *bb;

// 	aa = (*a)->top;
// 	bb = (*b)->top;
// 	while (aa || bb)
// 	{
// 		if (aa)
// 		{
// 			printf("A_ %d: %d", cnt, aa->value);
// 			aa = aa->next;
// 		}
// 		printf("\t\t");
// 		if (bb)
// 		{
// 			printf("B_ %d: %d", cnt, bb->value);
// 			bb = bb->next;
// 		}
// 		printf("\n");
// 		cnt++;
// 		if (aa == NULL && bb == NULL)
// 			break;
// 	}
// 	printf("============\t============\n\n");
// }

// void	move_from_b(t_stack **a, t_stack **b, t_value *pivot)
// {
// 	if ((*b)->top->value < pivot->pivot_1)
// 	{
// 		rb(b);
// 		pivot->rb++;
// 	}
// 	else
// 	{
// 		pa(a, b);
// 		pivot->pa++;
// 		if ((*a)->top->value < pivot->pivot_2)
// 		{
// 			printf("ddddd\n");
// 			ra(a);
// 			pivot->ra++;
// 			// print_result(a, b);
// 		}
// 	}
// 	// print_result(a, b);
// }

// void	top_value_min_b(t_stack **b, int max)

// {
// 	if ((*b)->size == 3)
// 	{
// 		rb(b);
// 		printf("(*b) : %d, %d, %d\n", (*b)->top->value, (*b)->top->next->value, (*b)->top->next->next->value);
// 		if ((*b)->top->next->value == max)
// 		{
// 			sb(b);
// 		}
// 		printf("mmmmmmmmmmmmmmmmmmmmmmmm\n");
// 		printf("(*b) : %d, %d, %d\n", (*b)->top->value, (*b)->top->next->value, (*b)->top->next->next->value);
// 	}
// 	else
// 	{
	
// 		return;
// 	}
// }

// void	top_next_value_min_b(t_stack **b, int max)
// {
// 	if ((*b)->size == 3)
// 	{
// 		rrb(b);
// 		if ((*b)->top->next->value == max)
// 			sb(b);
// 	}
// 	else
// 	{

// 		return;
// 	}
// }

// void	top_next_next_value_min_b(t_stack **b, int max)
// {
// 	if ((*b)->size == 3)
// 	{
// 		if ((*b)->top->next->value == max)
// 			sb(b);
// 	}
// 	else
// 		return ;
// }


// void	size_three_b(t_stack **a, t_stack **b, int size)
// {
// 	int	min;
// 	int	max;
	
// 	check_list(a,b);
// 	min = get_min_value((*b)->top, size); // 1
// 	max = get_max_value((*b)->top, size); // 4
// 	printf("min : %d , max : %d\n", min, max);
// 	if ((*b)->top->value == min)
// 		top_value_min_b(b, max);
// 	else if ((*b)->top->next->value == min)
// 		top_next_value_min_b(b, max);
// 	else if ((*b)->top->next->next->value == min)
// 	{
// 		top_next_next_value_min_b(b, max);
// 	}
// 	pa(a, b);
// 	pa(a, b);
// 	pa(a, b);
// }





// void	handle_under_three(t_stack **a, t_stack **b, int flag, int size)
// {

// 	if (size == 3)
// 	{
// 		if (flag == A)
// 		{
			
// 			size_three_a(a, size);
			
// 		}
// 		else
// 		{

// 			write(1, "awd\n", 4);
// 			size_three_b(a, b, size);

// 			printf("size : %d\n", size);

// 		}
		
// 	}
// 	else if (size == 2)
// 	{
// 		size_two(a, b, flag);

// 	}
// 	else if (size == 1)
// 	{

// 		if (flag == B)
// 		{
// 			printf("dnbu\n");

// 			pa(a, b);
// 		}
// 		printf("done\n");
// 	}
// }


// int	exceptional_cases_b(t_stack **a, t_stack **b, int size)
// {
// 	if (size <= 3)
// 	{
	

// 		handle_under_three(a, b, B, size);
// 		return (0);
// 	}

// 	return (1);
// }

// void	return_rb(t_stack **a, t_stack **b, t_value *pivot)
// {
// 	int	rrd;
// 	int	rem;

// 	rrd = pivot->ra;
// 	rem = pivot->rb - rrd;
// 	while (rrd--)
// 		rrr(a,b);
// 	while (rem--)
// 		rrb(b);
// }


// void	return_ra(t_stack **a, t_stack **b, t_value *pivot)
// {
// 	int	rrd;
// 	int	rem;

// 	rrd = pivot->rb;
// 	rem = pivot->ra - rrd;
// 	while(rrd--)
// 		rrr(a,b);
// 	while(rem--)
// 	{
// 		rra(a);
// 	}
// }
// void	ft_sort_int_tab_b(int *tab, int size)
// {
// 	int	a;
// 	int	b;
// 	int	temp;

// 	a = 0;
// 	while (a < size)
// 	{
// 		b = a + 1;
// 		while (b < size)
// 		{
// 			if (tab[a] > tab[b])
// 			{
// 				temp = tab[a];
// 				tab[a] = tab[b];
// 				tab[b] = temp;
// 			}
// 			b++;
// 		}
// 		a++;
// 	}
// }

// void assign_index_b(t_stack **a, int size)
// {
//     int i;
//     int *aa;
//     t_node *ptr;

//     aa = (int *)malloc(size * sizeof(int));
//     i = 0;
//     ptr = (*a)->top;
//     while (ptr)
//     {
//         aa[i] = ptr->value;
//         ptr = ptr->next;
//         i++;
//     }
//     ft_sort_int_tab_b(aa, size);

//     ptr = (*a)->top;
//     while (ptr)
//     {
// 		i = 0;
//         while (i < size)
//         {
//             if (ptr->value == aa[i])
//             {
//                 ptr->index = i + 1;
//                 break;
//             }
// 			i++;
//         }
// 		printf("index: %d\n", ptr->index);
//         ptr = ptr->next;
//     }
// }

// // pivot 다시 정하기
// void select_pivot_b(int size, t_stack **b, t_value *pivot)
// {
// 	int first;
// 	int second;
// 	t_node *fa;


// 	fa = (*b)->top;
// 	assign_index_b(b, size);
// 	// first = 0;
// 	// second = 0;
// 	//printf("index1 : %d\n", a->top->index);
// 	//printf("index2 : %d\n", a->top->next->index);
// 	//printf("index3 : %d\n", a->top->next->next->index);
// 	//printf("index4 : %d\n", a->top->next->next->next->index);
// 	//printf("index5 : %d\n", a->top->next->next->next->next->index);
// 	//printf("index6 : %d\n", a->top->next->next->next->next->next->index);
// 	first = (size / 3 + 1);
// 	second = (size - first +1);
// 	printf("first : %d second : %d \n", first, second);
	
// 	while (fa)
// 	{
// 		if (fa->index == first)
// 			pivot->pivot_1 = fa->value;
// 		if (fa->index == second)
// 			pivot->pivot_2 = fa->value;
// 		fa = fa->next;
// 	}
	
// }
// void	b_to_a(t_stack **a, t_stack **b, int size, int *cnt)
// {
// 	printf("b_to_a\n");
// 	t_value	pivot;
// 	int		temp;

	
// 	if (size <= 3)
// 	{
// 		exceptional_cases_b(a, b, size);
// 		check_list(a, b);
// 		return ;
// 	}

// 	t_value_zero(&pivot);
// 	select_pivot_b(size, b, &pivot);
		
// 	temp = size;
// 	while (temp--)
// 	{
// 		move_from_b(a, b, &pivot);

// 	}

// 	a_to_b(a, b, pivot.pa - pivot.ra, cnt);


	

// 	if (pivot.ra > pivot.rb)
// 		return_ra(a, b, &pivot);
// 	else
// 		return_rb(a, b, &pivot);

// 	a_to_b(a, b,pivot.ra, cnt);
// 	b_to_a(a, b, pivot.rb, cnt);

// }








// int    get_max_value(t_node *node, int size)
// {
// 	int	max;

// 	max = node->value;
// 	while (size--)
// 	{
// 		if (max < node->value)
// 			max = node->value;
// 		if (node->next)
// 			node = node->next;
// 		else
// 			break;
// 	}
// 	while (node->prev)
// 		node = node->prev;
// 	return (max);
// }

// int		get_min_value(t_node *node, int size)
// {
// 	int min;

// 	min = node->value;
// 	while (size--)
// 	{
// 		if (min > node->value)
// 			min = node->value;
// 		if (node->next)
// 			node = node->next;
// 		else
// 			break;
// 	}
// 	while (node->prev)
// 		node = node->prev;
// 	return (min);
// }
// void	ft_sort_int_tab(int *tab, int size)
// {
// 	int	a;
// 	int	b;
// 	int	temp;

// 	a = 0;
// 	while (a < size)
// 	{
// 		b = a + 1;
// 		while (b < size)
// 		{
// 			if (tab[a] > tab[b])
// 			{
// 				temp = tab[a];
// 				tab[a] = tab[b];
// 				tab[b] = temp;
// 			}
// 			b++;
// 		}
// 		a++;
// 	}
// }

// void assign_index(t_stack **a, int size)
// {
//     int i;
//     int *aa;
//     t_node *ptr;

//     aa = (int *)malloc(size * sizeof(int));
//     i = 0;
//     ptr = (*a)->top;
//     while (ptr)
//     {
//         aa[i] = ptr->value;
//         ptr = ptr->next;
//         i++;
//     }
//     ft_sort_int_tab(aa, size);

//     ptr = (*a)->top;
//     while (ptr)
//     {
// 		i = 0;
//         while (i < size)
//         {
//             if (ptr->value == aa[i])
//             {
//                 ptr->index = i + 1;
//                 break;
//             }
// 			i++;
//         }
	
//         ptr = ptr->next;
//     }
// }


// void select_pivot(int size, t_stack **a, t_value *pivot)
// {
// 	int first;
// 	int second;
// 	t_node *fa;


// 	fa = (*a)->top;
// 	assign_index(a, size);

// 	first = (size / 3 + 1);
// 	second = (size - first +1);
// 	printf("first : %d second : %d \n", first, second);
	
// 	while (fa)
// 	{
// 		if (fa->index == first)
// 			pivot->pivot_1 = fa->value;
// 		if (fa->index == second)
// 			pivot->pivot_2 = fa->value;
// 		fa = fa->next;
// 	}
// 	printf("pivot1 : %d pivot2 : %d\n", pivot->pivot_1, pivot->pivot_2);
// }

// void	push_swap(t_stack **a, t_stack **b)
// {
// 	int	cnt;
// 	cnt = 0;
// 	// if (a->size == 5)
// 	// {
// 	// 	printf("fuck\n");
// 	// 	handle_arg_five(a, b);
// 	// }
// 	// else
// 	a_to_b(a, b, (*a)->size, &cnt);
// }

// void	t_value_zero(t_value *var)
// {
// 	var->ra = 0;
// 	var->rb = 0;
// 	var->pa = 0;
// 	var->pb = 0;
// }


// int	exceptional_cases(t_stack **a, t_stack **b, int size)
// {
// 	if (size <= 3)
// 	{
// 		// printf("size : %d\n", size);
// 		//printf("dddddddddd\n");
// 		handle_under_three(a, b, A, size);
// 		return (0);
// 	}
// 	// else if (size == 5)
// 	// {//printf("dddddddddd\n");
// 	// 	hanlde_sort_five(a, b, A, 5);
// 	// 	//printf("dddddddddd\n");
// 	// 	return (0);
		
// 	// }
// 	//else
// 		return (1);
// }

// void	return_rbb(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
// {
// 	int	rrd;
// 	int	rem;

// 	rrd = pivot->ra;
// 	rem = pivot->rb - rrd;
// 	if ((*cnt) > 0)
// 	{
// 		while (rrd--)
// 		{
// 			rrr(a, b);
// 		}
// 		while (rem--)
// 			rrb(b);
// 	}
// 	else
// 	{
// 		rrd = pivot->rb;
// 		while (rrd--)
// 			rrb(b);
// 	}
// }


// void	return_raa(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
// {
// 	int	rrd;
// 	int	rem;

// 	rrd = pivot->rb;
// 	rem = pivot->ra - rrd;
// 	if ((*cnt) > 0)
// 	{
// 		while (rrd--)
// 			rrr(a, b);
// 		while (rem--)
// 			rra(a);
// 	}
// 	else
// 	{
// 		while (rrd--)
// 			rrb(b);
// 	}
// }

// void	a_to_b(t_stack **a, t_stack **b, int size, int *cnt)
// {
// 	printf("a_to_b\n");
// 	t_value	pivot;
// 	int		temp;
	
 
// 	if (exceptional_cases(a, b, size) == 0)
// 		return ;
// 	t_value_zero(&pivot);
// 	select_pivot(size, a, &pivot);
	
// 	temp = size;
// 	while (temp--)
// 	{

// 		move_from_a(a, b, &pivot);
// 	}
	

// 	if (pivot.ra > pivot.rb)
// 		return_raa(a, b, &pivot, cnt);
// 	else
// 	{
// 		return_rbb(a, b, &pivot, cnt);
// 	}
// 	a_to_b(a, b, pivot.ra, cnt);


// 	printf("rb : %d\n", pivot.rb);
// 		// printf("xx : %d\n");
// 	b_to_a(a, b, pivot.rb, cnt);

// 	b_to_a(a, b, pivot.pb - pivot.rb, cnt);
//     check_list(a, b);


// }