#include "push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	select_pivot(a->size, a, &var);
}

void	select_pivot(int size, t_stack *stack, t_value *var)
{
	int	max;

	max = get_max_value(stack->top, r);
}

int    get_max_value(t_node *node, int size)
{
	int	max;

	max = node->value;
	while (size--)
	{
		if (max < node->value)
			max = node->value;
		if (node->next)
			node = node->next;
		else
			break ;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}