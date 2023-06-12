/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:41:12 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/23 17:08:01 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	char	*c;

	a = 0;
	b = 0;
	c = (char *)src;
	if (dstsize == 0)
		return (ft_strlen(src) + dstsize);
	while (dst[a] != '\0')
		a++;
	while (c[b] != '\0' && a + b + 1 < dstsize)
	{
		dst[a + b] = c[b];
		b++;
	}
	dst[a + b] = '\0';
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
		return (ft_strlen(src) + a);
}
