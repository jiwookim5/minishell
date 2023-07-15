/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:52:30 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/22 21:11:38 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int print_max = 0;
void check_list(t_stack **a, t_stack **b)
{
	if (print_max == 3000)
		return; // exit(1);
	
	print_max++;
	printf("print_max_idx: %d\n", print_max);
	printf("\n");
	int cnt = 1;
	printf("============\t============\n");

	t_node *aa;
	t_node *bb;

	aa = (*a)->top;
	bb = (*b)->top;
	while (aa || bb)
	{
		if (aa)
		{
			printf("A_ %d: %d", cnt, aa->value);
			//write(1, "A\n", 2);
			aa = aa->next;
		}
		printf("\t\t");
		if (bb)
		{
			printf("B_ %d: %d", cnt, bb->value);
			//write(1, "B\n", 2);
			bb = bb->next;
		}
		printf("\n");
		cnt++;
		if (aa == NULL && bb == NULL)
			break;
	}
	printf("============\t============\n\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc > 1)
	{
		a = stack_init();
		a->top = make_stack(argc, argv, &a);
		same_check(a->top);
		b = stack_init();
		push_swap(&a, &b);
		check_list(&a, &b);
		free_st(&a, &b);
	}
}
