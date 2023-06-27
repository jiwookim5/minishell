/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 14:29:59 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/21 15:13:29 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	ft_lstsize_two(t_node *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst != NULL)
// 	{
//         size++;
//         printf("dddddd\n");
// 		lst = lst->next;

// 	}
// 	return (size);
// }

t_node	*ft_lstlast_two(t_node *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_front_two(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;

}


void	ft_lstadd_back_two(t_node **lst, t_node *new)
{
	if (*lst == 0)
		*lst = new;
	else
		ft_lstlast_two(*lst)->next = new;
}

void    sa(t_stack *a)
{
    t_node *temp;
    // t_node *top_next;
    
    if (a->top)
    {
        // top_next = a->top->next;
        // temp = a->top;
        // a->top->next = temp;
        // a->top = top_next;
        temp = a->top;
        a->top = a->top -> next;
        temp->next = a->top->next;
        a->top->next = temp;

        write(1, "sa\n", 3);
    }
    else
        ft_error();
    // write(1, "sa\n", 3);
    // printf("%d\n", a->top->value);
    // printf("%d\n", a->top->next->value);
    // printf("%d\n", a->top->next->next->value);
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
        write(1, "sb\n", 3);
    }
    else
        ft_error();
    // printf("%d\n", b->top->value);
    // printf("%d\n", b->top->next->value);
}

void    ss(t_stack *a, t_stack *b)
{
    if (a->top && b->top)
    {
        sa(a);
        sb(b);
        write(1, "ss\n", 3);
    }
    else
        ft_error();
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
    write(1, "pa\n", 3);
    // printf("a == %d\n", (*a)->top->value);

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
    write(1, "pb\n", 3);
    // printf("a1 == %d\n", (*a)->top->value);
    // printf("a2 == %d\n", (*a)->top->next->value);
    // printf("a3 == %d\n", (*a)->top->next->next->value);
    // printf("b1 == %d\n", (*b)->top->value);
    // printf("b2 == %d\n", (*b)->top->next->value);
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
    write(1, "ra\n", 3);
    // printf("a1 == %d\n", (*a)->top->value);
    // printf("a2 == %d\n", (*a)->top->next->value);
    // printf("a3 == %d\n", (*a)->top->next->next->value);
    // printf("a4 == %d\n", (*a)->top->next->next->next->value);
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
    write(1, "rb\n", 3);
    // printf("a1 == %d\n", (*b)->top->value);
    // printf("a2 == %d\n", (*b)->top->next->value);
    // printf("a3 == %d\n", (*b)->top->next->next->value);
    // printf("a4 == %d\n", (*b)->top->next->next->next->value);
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a);
    rb(b);
    write(1, "rr\n", 3);
}


void rra(t_stack **a)
{
    t_node *last;
    t_node *front_last;

    if ((*a)->top == NULL || (*a)->top->next == NULL)
        return;

    front_last = (*a)->top;

    while (front_last->next->next != NULL)
    {
        front_last = front_last->next;
    }

    last = ft_lstlast_two((*a)->top);

    if (last == NULL)
        return;

    front_last->next = NULL;
    last->next = (*a)->top;
    (*a)->top = last;

    write(1, "rra\n", 4);
    // printf("a1 == %d\n", (*a)->top->value);
    // printf("a2 == %d\n", (*a)->top->next->value);
    // printf("a3 == %d\n", (*a)->top->next->next->value);

}

void rrb(t_stack **b)
{
    t_node *last;
    t_node *front_last;

    if ((*b)->top == NULL || (*b)->top->next == NULL)
        return;

    front_last = (*b)->top;

    while (front_last->next->next != NULL)
    {
        front_last = front_last->next;
    }

    last = ft_lstlast_two((*b)->top);

    if (last == NULL)
        return;

    front_last->next = NULL;
    last->next = (*b)->top;
    (*b)->top = last;

    write(1, "rra\n", 4);
    // printf("a1 == %d\n", (*b)->top->value);
    // printf("a2 == %d\n", (*b)->top->next->value);
    // printf("a3 == %d\n", (*b)->top->next->next->value);

}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a);
    rrb(b);
    write(1, "rrr\n", 4);
}
