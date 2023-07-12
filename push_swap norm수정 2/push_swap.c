
#include "push_swap.h"

int	move_ones(t_stack **a, t_stack **b, t_value *pivot, int *temp)
{
if ((*a)->top->value >= pivot->pivot_2)
	{
		ra(a, 2);
		pivot->ra++;
	}
	else
	{
		pb(a, b);
		pivot->pb++;
		if ((*b)->top->value < pivot->pivot_1)
		{
			if ((*a)->top->value >= pivot->pivot_2)
			{
				if (*temp - 1 == -1)
				{
					rb(b, 2);
					pivot->rb++;
					return (*temp);
				}
				rr (a, b);
				pivot->rb++;
				pivot->ra++;
				*temp = *temp - 1;
				return (*temp);
			}
			rb(b, 2);
			pivot->rb++;
		}
	}
	return (*temp);
}

void	sort_algorithm(t_stack **a, t_stack **b, int size, t_value *pivot)
{
	int temp;

	if (exceptional_cases(a, b, size) == 0)
		return ;
	select_pivot(size, a, pivot);
	temp = size;
	while (temp-- > 0)
		temp = move_ones(a, b, pivot, &temp);
}


void	push_swap(t_stack **a, t_stack **b)
{
	int	cnt;
	t_value pivot;

	cnt = 0;
	if (is_sorted(a) == 1)
		return ;
	if ((*a)->size == 4)
		handle_arg_four(a, b);
	if ((*a)->size == 5)
		handle_arg_five(a, b);
	t_value_zero(&pivot);
	if (!(is_sorted(a)))
		sort_algorithm(a, b, (*a)->size, &pivot);
	a_to_b(a, b, pivot.ra, &cnt);
	b_to_a(a, b, pivot.pb - pivot.rb, &cnt);
	b_to_a(a, b, pivot.rb, &cnt);
}