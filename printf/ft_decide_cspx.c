/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decide_cspx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:12:49 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/05/18 17:54:27 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_decide_c(va_list arg)
{
	char	c;

	c = (char)va_arg(arg, int);
	if (ft_putchar_fd(c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_decide_s(va_list arg)
{
	char	*c;

	c = va_arg(arg, char *);
	if (c == 0)
	{
		if (ft_putstr_fd("(null)", 1) == -1)
			return (-1);
		return (6);
	}
	if (ft_putstr_fd(c, 1) == -1)
		return (-1);
	return (ft_strlen(c));
}

int	ft_decide_16_output(unsigned long long c, int *len)
{
	if (c > 0)
	{
		if (ft_decide_16_output(c / 16, len) == -1)
			return (-1);
		(*len)++;
		if (write(1, &"0123456789abcdef"[c % 16], 1) == -1)
			return (-1);
	}
	return (*len);
}

int	ft_decide_p(va_list arg)
{
	unsigned long long	c;
	int					len;

	len = 0;
	c = va_arg(arg, unsigned long long);
	if (c == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	len = len + 2;
	if (ft_decide_16_output(c, &len) == -1)
		return (-1);
	return (len);
}

int	ft_decide_x(va_list arg)
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
	if (ft_decide_16_output(x, &len) == -1)
		return (-1);
	return (len);
}
