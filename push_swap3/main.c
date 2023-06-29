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
        //printf("debug\n");
        //b라는 스택을 만듬
        b = stack_init();
        // while (a->size--)
        // {
        //     printf("%d\n",a->top->value);
        //     a->size--;
        //     a->top = a->top->next;
        // }
	printf("%d\n",a->top->value);
    // printf("%d\n",a->top->next->value);

    // printf("%d\n",a->top->next->next->next->value);
   
    push_swap(a,b);
    print_result(a, b);
    }
    return(0);
}