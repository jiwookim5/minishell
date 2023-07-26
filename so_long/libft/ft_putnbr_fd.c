/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:52:49 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/24 15:50:13 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	aaaa(int n, int fd)
{
	n = n * -1;
	write(fd, "-", 1);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	tmp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
	{
		n = aaaa(n, fd);
	}
	if (n < 10)
	{
		tmp = n + 48;
		write(fd, &tmp, 1);
		return ;
	}
	else
		ft_putnbr_fd (n / 10, fd);
	ft_putnbr_fd (n % 10, fd);
}
