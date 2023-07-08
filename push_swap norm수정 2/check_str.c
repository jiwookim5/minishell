/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 22:23:23 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/14 17:20:24 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chk_arg_length(char *arg)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (arg[0] == '+' || arg[0] == '-')
	{
		i++;
		len--;
	}
	while (arg[i] == ' ')
	{
		i++;
		if (arg[i] == '\0')
			ft_error();
	}
	while (arg[i++])
		len++;
	return (len);
}

void	number_check(char *str)
{
	int i;

	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
		i++;
	}
}

void	str_check(char *str)
{
	int	len;

	len = chk_arg_length(str);

	if (len > 11 || len < 0)
		ft_error();
	number_check(str);
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
