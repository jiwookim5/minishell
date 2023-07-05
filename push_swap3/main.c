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
	printf("sdgsklgsd\n");
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


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    
    if (argc > 1)
    {
        //a 라는 스택을 만들고
        a = stack_init();
        //a 스택 top 에 연결한 노드의 첫번째꺼를 넣는다.
        a->top = make_stack(argc, argv, &a);
        //중복 체크
        same_check(a->top);
        ////printf("debug\n");
        //b라는 스택을 만듬

        b = stack_init();

        // while (a->size--)
        // {
        //     //printf("%d\n",a->top->value);
        //     a->size--;
        //     a->top = a->top->next;
        // }
	    //printf("%d\n",a->top->value);
    // //printf("%d\n",a->top->next->value);

    // //printf("%d\n",a->top->next->next->next->value);

		// pb(&a, &b);
		// pb(&a, &b);
		// pb(&a, &b);
		// pb(&a, &b);
		// rb( &b);
		// rrb(&b);

		push_swap(&a, &b);
		// while(1)
		// {

		// }
        //printf("debug\n");
		// while (a->top)
		// {
		// 	a->top = a->top->next;
		// 	a->bottom->value = a->top->value;
		// }
		// printf("xxxxx\n");
		// printf("(*a)->bottom->value : %d\n", a->bottom->value);
        //print_result(&a, &b);
        ////printf("jaeyojun a->content : %d\n", a->top->value);
		// while (a->top)
		// {
		// 	free(a->top);
		// 	a->top = a->top->next;
		// }
    }

	checker(&a, &b);
	check_list(&a, &b);

    return(0);
}