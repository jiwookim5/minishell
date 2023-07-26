/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 12:47:48 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/15 13:17:22 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*a;
	char	b;
	int		i;

	a = (char *)str;
	b = (char)c;
	i = 0;
	while (a[i] != b)
	{
		if (a[i] == '\0')
			return (0);
		i++;
	}
	return (&a[i]);
}
