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
void    ra(t_stack **a, int i);
t_node	*ft_lstlast_two(t_node *lst);
void	push_swap(t_stack **a, t_stack **b);
void	ft_lstadd_back_two(t_node **lst, t_node *new);
void    rb(t_stack **b, int i);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a, int i);
void    rrb(t_stack **b, int i);
void    rrr(t_stack **a, t_stack **b);
void	t_value_zero(t_value *var);

void select_pivot(int size, t_stack **stack, t_value *pivot);
int    get_max_value(t_node *node, int size);
int		get_min_value(t_node *node, int size);
void	size_three_a(t_stack **a, int size);


int	move_from_a(t_stack **a, t_stack **b, t_value *pivot , int *temp);
void print_result(t_stack **a, t_stack **b);
void assign_index(t_stack **stack_a, int stack_size);
int	move_from_b(t_stack **a, t_stack **b, t_value *pivot, int *temp);
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
void assign_index_b(t_stack **b, int size);
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
int		is_sorted(t_stack **a);
// void	checker(t_stack **a, t_stack **b);

#endif


