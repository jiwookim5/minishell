
#include "push_swap.h"

void		handle_sort_four(t_stack **a, t_stack **b, int flag, int size)
{
	if (flag == A)
		sort_four_a(size, a, b);
	else
		sort_four_b(size, a, b);
	size_three_a(a, 3);
	if (flag == A)
		pa(a, b);
	else
		pb(a, b);
}

void		handle_sort_five(t_stack **a, t_stack **b, int flag, int size)
{
	if (flag == A)
		sort_five_a(size, a, b);
	else
		sort_five_b(size, a, b);
	size_three_a(a, 3);
	size_two(a, b, B);
}