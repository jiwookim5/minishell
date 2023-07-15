/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decide_xx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:12:18 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/05/18 17:54:41 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_decide_upper_output(unsigned long long c, int *len)
{
	if (c > 0)
	{
		if (ft_decide_upper_output(c / 16, len) == -1)
			return (-1);
		(*len)++;
		if (write(1, &"0123456789ABCDEF"[c % 16], 1) == -1)
			return (-1);
	}
	return (*len);
}

int	ft_decide_xx(va_list arg)
{
	unsigned int	x;
	int				len;

	len = 0;
	x = va_arg(arg, unsigned int);
	if (x == 0)
	{
		if (ft_putchar_fd('0', 1) == -1)
			return (-1);
		return (1);
	}
	return (ft_decide_upper_output(x, &len));
}
