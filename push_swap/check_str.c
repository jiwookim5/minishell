/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:23:23 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/02 16:14:17 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//12a 이런거 처리 / 숫자만 있는지
int	number_check(char *str)
{
	int i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] <= '0' && str[i] >= '9')
			return (0);
		i++;
	}
	return (1);
}

int	str_check(char *str)
{
	int	num;

	num = number_check(str);
	if (!num)
		return (0);
	else
		return (1);
}

void	same_check(t_node *a)
{
	t_node	*temp;
	int		num;
	
	while (a->next)
	{
		num = a->value;
		temp = a->next;
		while (a->next)
		{
			if (num == temp->value)
				ft_error();
			if (temp->next) 
				temp = temp->next;
			else
				break;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}
