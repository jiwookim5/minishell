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

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc > 1)
    {
        a = stack_init();
        a->top = make_stack(argc, argv, &a);
        same_check(a->top);
        b = stack_init();
        push_swap(&a, &b);
        // checker(&a, &b);
    }
    return(0);
}
