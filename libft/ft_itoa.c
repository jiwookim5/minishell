/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 08:22:23 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/24 15:49:43 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
	{
		len++;
		return (len);
	}
	else if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa1(char *str, long nb, size_t i)
{
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i--] = 48 + (nb % 10);
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	i;

	nb = n;
	i = len(nb);
	str = (char *)malloc(i + 1);
	if (str == 0)
		return (0);
	str[i--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	ft_itoa1 (str, nb, i);
	return (str);
}
