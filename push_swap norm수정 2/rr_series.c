
#include "push_swap.h"


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

void    ra(t_stack **a, int i)
{
	t_node	*first;
	t_node	*second;

    if ((*a)->top->next && (*a)->top)
    {
        first = (*a)->top;
        second = (*a)->top->next;
        ft_lstadd_back_two(&((*a)->top), first);
        first->next = NULL;
        (*a)->top = second;
    }
    if (i != 1)
        write(1, "ra\n", 3);
}

void    rb(t_stack **b, int i)
{
	t_node	*first;
	t_node	*second;

    if((*b)->top && ((*b)->top->next))
    {
	first = (*b)->top;
    second = (*b)->top->next;
    ft_lstadd_back_two(&((*b)->top), first);
    first->next = NULL;
    (*b)->top = second;
    }
    if (i != 1)
        write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    ra(a, 1);
    rb(b, 1);
    write(1, "rr\n", 3);
}