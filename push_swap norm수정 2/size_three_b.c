
#include "push_swap.h"

void	top_value_min_b(t_stack **b, int max)

{
	if ((*b)->size == 3)
	{
		rb(b,2);
		if ((*b)->top->next->value == max)
		{
			sb(b);
		}
	}
	else
	{
		sb(b);
		rb(b,2);
		sb(b);
		rrb(b, 2);
		if ((*b)->top->next->value == max)
			sb(b);
		return;
	}
}

void	top_next_value_min_b(t_stack **b, int max)
{
	if ((*b)->size == 3)
	{
		rrb(b, 2);
		if ((*b)->top->next->value == max)
			sb(b);
	}
	else
	{
		rb(b,2);
		sb(b);
		rrb(b, 2);
		if ((*b)->top->next->value == max)
			sb(b);
		return;
	}
}

void	top_next_next_value_min_b(t_stack **b, int max)
{
	
	if ((*b)->size <= 3)
	{

		if ((*b)->top->next->value == max)
			sb(b);
	}
	else
		return ;
}

void	size_three_b(t_stack **a, t_stack **b, int size)
{
	int	min;
	int	max;
	
	min = get_min_value((*b)->top, size);
	max = get_max_value((*b)->top, size);
	if ((*b)->top->value == min)
		top_value_min_b(b, max);
	else if ((*b)->top->next->value == min)
		top_next_value_min_b(b, max);
	else if ((*b)->top->next->next->value == min)
		top_next_next_value_min_b(b, max);
	pa(a, b);
	pa(a, b);
	pa(a, b);
}