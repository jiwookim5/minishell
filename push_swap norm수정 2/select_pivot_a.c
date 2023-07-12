#include "push_swap.h"

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
			break;
	}
	while (node->prev)
		node = node->prev;
	return (max);
}

int		get_min_value(t_node *node, int size)
{
	int min;

	min = node->value;
	while (size--)
	{
		if (min > node->value)
			min = node->value;
		if (node->next)
			node = node->next;
		else
			break;
	}
	while (node->prev)
		node = node->prev;
	return (min);
}
void	ft_sort_int_tab(int *tab, int size)
{
	int	a;
	int	b;
	int	temp;

	a = 0;
	while (a < size)
	{
		b = a + 1;
		while (b < size)
		{
			if (tab[a] > tab[b])
			{
				temp = tab[a];
				tab[a] = tab[b];
				tab[b] = temp;
			}
			b++;
		}
		a++;
	}
}

void assign_index(t_stack **a, int size)
{
    int i;
    int *aa;
    t_node *ptr;
	t_node *compare_ptr;

    aa = (int *)malloc(size * sizeof(int));
    i = 0;
    ptr = (*a)->top;
    while (ptr && i < size)
    {
		ptr->index = 1;
        aa[i] = ptr->value;
        ptr = ptr->next;
  
		i++;
    }
    ft_sort_int_tab(aa, size);

    ptr = (*a)->top;
    while (ptr)
    {
		i = 0;
		compare_ptr = (*a)->top;
        while (compare_ptr)
        {
            if (ptr->value == aa[i])
            {
                ptr->index = i + 1;
				break;
            }
			compare_ptr = compare_ptr->next;
			i++;
		}
        ptr = ptr->next;
    }
	free(aa);

}

void select_pivot(int size, t_stack **a, t_value *pivot)
{
	int first;
	int second;
	t_node *fa;


	fa = (*a)->top;
	assign_index(a, size);
	first = (size / 3 + 1);
	second = (size - first +1);
	while (fa)
	{
		if (fa->index == first)
			pivot->pivot_1 = fa->value;
		if (fa->index == second)
			pivot->pivot_2 = fa->value;
		fa = fa->next;
	}
}