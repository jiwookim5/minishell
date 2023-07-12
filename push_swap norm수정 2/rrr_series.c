
#include "push_swap.h"

void	ft_lstadd_front_two(t_node **lst, t_node *new)
{
	new->next = *lst;
	*lst = new;

}

void rra(t_stack **a, int i)
{
    t_node   *temp;
   t_node   *last_front;
   t_node   *stack;

   stack = (*a)->top;
   if (!(stack && stack->next))
      return ;
   temp = stack;
   while (temp->next)
   {
      last_front = temp;
      temp = temp->next;
   }
   temp->next = stack;
   last_front->next = NULL;
   (*a)->top = temp;
   if (i != 1)
        write(1, "rra\n", 4);
}

void rrb(t_stack **b, int i)
{
    t_node   *temp;
    t_node   *last_front;
    t_node   *stack;

    stack = (*b)->top;
    if (!(stack && stack->next))
        return ;
    temp = stack;
    while (temp->next)
    {
        last_front = temp;
        temp = temp->next;
    }
    temp->next = stack;
    last_front->next = NULL;
    (*b)->top = temp;
    if (i != 1)
        write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b)
{
    rra(a, 1);
    rrb(b, 1);
    write(1, "rrr\n", 4);
}
