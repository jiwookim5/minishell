/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:55:42 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/22 09:59:13 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	char	*c;

	a = 0;
	b = 0;
	c = (char *)src;
	while (c[a] != '\0')
		a++;
	if (dstsize != 0)
	{
		while ((c[b] != '\0') && b < (dstsize -1))
		{
			dst[b] = c[b];
			b++;
		}
			dst[b] = '\0';
	}
	return (a);
}
