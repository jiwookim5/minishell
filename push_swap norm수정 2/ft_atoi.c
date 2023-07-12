/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:11:42 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/06/14 17:21:47 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	t_value_zero(t_value *var)
{
	var->ra = 0;
	var->rb = 0;
	var->pa = 0;
	var->pb = 0;
}

long long	ft_atoi(char *str)
{
	int			a;
	long long	b;
	long long	res;
	long long	final;

	str_check(str);
	a = 0;
	b = 1;
	res = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32 || str[a] == 34)
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		res *= 10;
		res += str[a] - '0';
		a++;
	}
	final = res * b;
	if (final > 2147483647 || final < -2147483648)
		ft_error();
	return (final);
}
