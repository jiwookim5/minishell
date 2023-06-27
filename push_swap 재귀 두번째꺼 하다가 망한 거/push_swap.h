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
// int	ft_lstsize_two(t_node *lst);
t_node	*ft_lstlast_two(t_node *lst);
void	push_swap(t_stack *a, t_stack *b);
void	ft_lstadd_back_two(t_node **lst, t_node *new);
void    rb(t_stack **b);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a);
void    rrb(t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void	t_value_zero(t_value *var);
void	a_to_b(t_stack *a, t_stack *b, int size, int *xx);
void select_pivot(int size, t_stack *stack, t_value *pivot);
int    get_max_value(t_node *node, int size);
int		get_min_value(t_node *node, int size);
int	size_three(t_stack *a, int size, int i, t_value *pivot);
int	top_next_next_value_min(t_stack *a, int max, int i);
int	top_next_value_min(t_stack *a, int max, int i, t_value *pivot);
int	top_value_min(t_stack *a, int max, int i);
int	move_from_a(t_stack *a, t_stack *b, t_value *pivot);
void print_result(t_stack *a, t_stack *b);
void assign_index(t_stack *stack_a, int stack_size);
int	move_from_b(t_stack *a, t_stack *b, t_value *pivot);
void	b_to_a(t_stack *a, t_stack *b, int size, int *xx);


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

// void		b_to_a(int r, t_stack *a, t_stack *b, int *cnt)
// {
// 	int		r_temp;
// 	t_value	var;

// 	(*cnt)++;
// 	if (!exceptional_cases(r, a, b))
// 		return ;
// 	init_value(&var);
// 	select_pivot(r, b, &var);
// 	r_temp = r;
// 	while (r_temp--)
// 		push_rotate_b(a, b, &var);
// 	a_to_b(var.pa - var.ra, a, b, cnt);
// 	if (var.ra > var.rb)
// 		back_to_orig_ra(a, b, &var);
// 	else
// 		back_to_orig_rb(a, b, &var);
// 	a_to_b(var.ra, a, b, cnt);
// 	b_to_a(var.rb, a, b, cnt);
// }
