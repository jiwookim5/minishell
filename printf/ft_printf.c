/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:21:17 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/05/18 17:55:31 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(const char *format, va_list ap, int error_check, int len)
{
	int	i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			error_check = len;
			len += (ft_distinguish(ap, format[i + 1]));
			if (error_check > len)
				return (-1);
			i++;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;
	int		i;
	int		error_check;

	error_check = 0;
	va_start(ap, format);
	len = 0;
	i = 0;
	if (ft_strchr((char *)format, '%') == 0)
	{
		if (ft_putstr_fd((char *)format, 1) == -1)
			return (-1);
		return (ft_strlen(format));
	}
	len = ft_percent(format, ap, error_check, len);
	if (len == -1)
		return (-1);
	va_end(ap);
	return (len);
}

int	main()
{
	char a = 'a';
	char *p = &a;
	int num1 = printf("%p\n", p);
	int num2 = ft_printf("%p\n", p);
	printf ("num1 : %d, num2 : %d", num1, num2);
	int num1 = printf(" %x \n", -10);
	int num2 = ft_printf(" %x \n", -10);
	printf("num2 : %d", num2);
	printf("num1 : %d, num2 : %d", num1, num2);
	return (0);
}
