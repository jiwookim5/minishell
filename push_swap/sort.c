/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:29:59 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/08 21:39:52 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_front_two(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;
}

t_node	*ft_lstlast_two(t_node *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_two(t_node **lst, t_node *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast_two(*lst)->next = new;
}



void    sort_fuc(t_stack *a, t_stack *b)
{
    //알고리즘
    sa(a);
    sb(b);
    ss(a, b);
	pa(&a, &b);
    pb(&a, &b);
    ra(&a);
    rb(&b);
    rr(&a, &b);
    rra(&a);
    rrb(&b);
    rrr(&a, &b);
}

void    sa(t_stack *a)
{
    t_node *temp;
    t_node *top_next;

    if (a->top)
    {
        top_next = a->top->next;
        temp = a->top;
        a->top = top_next;
        a->top->next = temp;
    }
    // printf("%d\n", a->top->value);
    // printf("%d\n", a->top->next->value);
}

void    sb(t_stack *b)
{
    t_node *temp;
    t_node *top_next;

    if (b->top)
    {
        top_next = b->top->next;
        temp = b->top;
        b->top = top_next;
        b->top->next = temp;
    }
    // printf("%d\n", b->top->value);
    // printf("%d\n", b->top->next->value);
}

void    ss(t_stack *a, t_stack *b)
{
    if (a->top && b->top)
    {
        sa(a);
        sb(b);
    }
}

void	pa(t_stack **a, t_stack **b)
{
	t_node *temp;

    if ((*b)->top)
    {
        temp = (*b)->top->next;
        ft_lstadd_front_two(&((*a)->top), (*b)->top);
        (*b)->top = temp;
    }
    printf("a == %d\n", (*a)->top->value);

}

void	pb(t_stack **a, t_stack **b)
{
	t_node *temp;

    if ((*a)->top)
    {
        temp = (*a)->top->next;
        ft_lstadd_front_two(&((*b)->top), (*a)->top);
        (*a)->top = temp;
    }
    printf("a1 == %d\n", (*a)->top->value);
    printf("a2 == %d\n", (*a)->top->next->value);
    printf("a3 == %d\n", (*a)->top->next->next->value);
    printf("b1 == %d\n", (*b)->top->value);
    printf("b2 == %d\n", (*b)->top->next->value);
}


void    ra(t_stack **a)
{
	t_node	*first;
	t_node	*second;

	first = (*a)->top;
    second = (*a)->top->next;
    ft_lstadd_back_two(&((*a)->top), first);
    first->next = NULL;
    (*a)->top = second;

    printf("a1 == %d\n", (*a)->top->value);
    printf("a2 == %d\n", (*a)->top->next->value);
    printf("a3 == %d\n", (*a)->top->next->next->value);
    printf("a4 == %d\n", (*a)->top->next->next->next->value);
}

void    rb(t_stack **b)
{
	t_node	*first;
	t_node	*second;

	first = (*b)->top;
    second = (*b)->top->next;
    ft_lstadd_back_two(&((*b)->top), first);
    first->next = NULL;
    (*b)->top = second;

    printf("a1 == %d\n", (*b)->top->value);
    printf("a2 == %d\n", (*b)->top->next->value);
    printf("a3 == %d\n", (*b)->top->next->next->value);
    printf("a4 == %d\n", (*b)->top->next->next->next->value);
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
}

void    rra(t_stack **a)
{
    t_node  *last;
    t_node  *front_last;

    front_last = (*a)->top;
    while (front_last->next->next)
        front_last = front_last->next;
    last = ft_lstlast_two((*a)->top);
    ft_lstadd_front_two(&(*a)->top, last);
    front_last->next = 0;
    printf("a1 == %d\n", (*a)->top->value);
    printf("a2 == %d\n", (*a)->top->next->value);
    printf("a3 == %d\n", (*a)->top->next->next->value);
    printf("a4 == %d\n", (*a)->top->next->next->next->value);
}

void    rrb(t_stack **b)
{
    t_node  *last;
    t_node  *front_last;

    front_last = (*b)->top;
    while (front_last->next->next)
        front_last = front_last->next;
    last = ft_lstlast_two((*b)->top);
    ft_lstadd_front_two(&(*b)->top, last);
    front_last->next = 0;
    printf("a1 == %d\n", (*b)->top->value);
    printf("a2 == %d\n", (*b)->top->next->value);
    printf("a3 == %d\n", (*b)->top->next->next->value);
    printf("a4 == %d\n", (*b)->top->next->next->next->value);
}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
}