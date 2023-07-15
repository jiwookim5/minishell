/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:11:42 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/24 15:39:26 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		a;
	long	b;
	long	res;

	a = 0;
	b = 1;
	res = 0;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
			a++;
	if (str[a] == 45 || str[a] == '+')
	{
		if (str[a] == '-')
			b *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		res *= 10;
		res += str[a] - '0';
		a++;
	}
	return ((int)(res * b));
}
