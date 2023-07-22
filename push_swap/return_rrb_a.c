/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_rrb_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:30:33 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/12 22:32:49 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	return_rbb(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
{
	int	rrd;
	int	rem;

	rrd = pivot->ra;
	rem = pivot->rb - rrd;
	if ((*cnt) > 0)
	{
		while (rrd--)
		{
			rrr(a, b);
		}
		while (rem--)
			rrb(b, 2);
	}
	else
	{
		rrd = pivot->rb;
		while (rrd--)
			rrb(b, 2);
	}
}

void	return_raa(t_stack **a, t_stack **b, t_value *pivot, int *cnt)
{
	int	rrd;
	int	rem;

	rrd = pivot->rb;
	rem = pivot->ra - rrd;
	if ((*cnt) > 0)
	{
		while (rrd--)
			rrr(a, b);
		while (rem--)
			rra(a, 2);
	}
	else
	{
		while (rrd--)
			rrb(b, 2);
	}
}

void	return_rb(t_stack **a, t_stack **b, t_value *pivot)
{
	int	rrd;
	int	rem;

	rrd = pivot->ra;
	rem = pivot->rb - rrd;
	while (rrd--)
		rrr(a, b);
	while (rem--)
		rrb(b, 2);
}

void	return_ra(t_stack **a, t_stack **b, t_value *pivot)
{
	int	rrd;
	int	rem;

	rrd = pivot->rb;
	rem = pivot->ra - rrd;
	while (rrd--)
		rrr(a, b);
	while (rem--)
	{
		rra(a, 2);
	}
}
