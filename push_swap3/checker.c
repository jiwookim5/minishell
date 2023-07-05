#include "push_swap.h"

int		is_sorted(t_stack **a)
{
	t_node	*node;

	node = (*a)->top;
	while (node)
	{
		if (node->next)
		{
			if (node->value > node->next->value)
				return (0);
		}
		if (node->next)
			node = node->next;
		else
			break ;
	}
	if (node->value == (*a)->bottom->value)
		return (1);
	else
		return (0);
}

void	checker(t_stack **a, t_stack **b)
{
     check_list(a, b);
    if (is_sorted(a) && !(*b)->top)
		printf("OK\n");
    
	else
		printf("KO\n");
}