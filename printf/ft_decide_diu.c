/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decide_diu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:15:49 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/05/18 17:54:36 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_len(int x)
{
	int	len;

	len = 0;
	if (x == -2147483647)
		return (11);
	if (x < 0)
	{
		x = (x * -1);
		len++;
	}
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = (x / 10);
		len++;
	}
	return (len);
}

int	ft_decide_d_i(va_list arg)
{
	int	x;

	x = va_arg(arg, int);
	if (ft_putnbr_fd(x, 1) == -1)
		return (-1);
	return (ft_nbr_len(x));
}

int	ft_unsigned_len(unsigned int x)
{
	int	len;

	len = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = (x / 10);
		len++;
	}
	return (len);
}

int	ft_decide_u_output(unsigned int n)
{
	if (n > 9)
	{
		if (ft_putnbr_fd(n / 10, 1) == -1)
			return (-1);
		if (ft_putnbr_fd(n % 10, 1) == -1)
			return (-1);
	}
	if (n <= 9)
		if (ft_putchar_fd(n + '0', 1) == -1)
			return (-1);
	return (0);
}

int	ft_decide_u(va_list arg)
{
	unsigned int	x;

	x = va_arg (arg, unsigned int);
	if (ft_decide_u_output(x) == -1)
		return (-1);
	return (ft_unsigned_len(x));
}
