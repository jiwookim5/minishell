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
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void    ra(t_stack **a);
t_node	*ft_lstlast_two(t_node *lst);
void	push_swap(t_stack *a, t_stack *b);
void	ft_lstadd_back_two(t_node **lst, t_node *new);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void	t_value_zero(t_value *var);
void	a_to_b(t_stack *a, t_stack *b, int size);
void select_pivot(int size, t_stack *stack, t_value *pivot);
int    get_max_value(t_node *node, int size);
int		get_min_value(t_node *node, int size);
void	size_three_a(t_stack *a, int size);


void	move_from_a(t_stack *a, t_stack *b, t_value *pivot);
void print_result(t_stack *a, t_stack *b);
void assign_index(t_stack *stack_a, int stack_size);
void	move_from_b(t_stack *a, t_stack *b, t_value *pivot);
void	b_to_a(t_stack *a, t_stack *b, int size);

void	top_next_value_min_b(t_stack *b, int max, int size);
void	top_next_next_value_min_b(t_stack *b, int max, int size);
void	size_three_b(t_stack *b, int size);
void	top_value_min_b(t_stack *b, int max, int size);
int	exceptional_cases(t_stack *a, t_stack *b, int size);
void		hanlde_sort_five(t_stack *a, t_stack *b, int flag, int size);
void	sort_five_a(int size, t_stack *a, t_stack *b);
void	sort_five_b(int size, t_stack *a, t_stack *b);
void		handle_arg_five(t_stack *a, t_stack *b);
int			get_mid_value_five(t_node *node);
int	sort_values(int value[]);
void	size_two(t_stack *a, t_stack *b, int flag);
void	top_next_next_value_min(t_stack *a, int max, int size);
void	top_next_value_min(t_stack *a, int max, int size);
void	top_value_min(t_stack *a, int max, int size);
int	exceptional_cases_b(t_stack *a, t_stack *b, int size);
void	handle_under_three(t_stack *a, t_stack *b, int flag, int size);

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

#endif






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

    ptr = a->top;
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
void select_pivot(int size, t_stack *a, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = a->top;
	assign_index(a, size);
	first = (size / 3);
	second = (size - first);
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

void	b_to_a(t_stack *a, t_stack *b, int size)
{
	t_value	pivot;
	int		temp;
	
	if (!exceptional_cases(a, b, size))
		return ;
	t_value_zero(&pivot);
	select_pivot(size, b, &pivot);
		
	temp = size;
	while (temp--)
	{
		move_from_b(a, b, &pivot);
	}

	a_to_b(a, b, pivot.ra);
	b_to_a(a, b, pivot.rb);

    print_result(a, b);

}


void	a_to_b(t_stack *a, t_stack *b, int size)
{
	// printf("size: %d\n", size);
	t_value	pivot;
	int		temp;
	
	if (exceptional_cases(a, b, size) == 0)
		return ;
	t_value_zero(&pivot);
	select_pivot(size, a, &pivot);
		
	temp = size;
	while (temp--)
	{

		move_from_a(a, b, &pivot);
		print_result(a, b);
	}
	
		printf("ra : %d\n", pivot.ra);
		a_to_b(a, b, pivot.ra);
		b_to_a(a, b, pivot.rb);
    	print_result(a, b);

}
