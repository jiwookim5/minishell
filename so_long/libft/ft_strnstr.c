/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:35:44 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/24 16:33:03 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_needle(size_t i, char *h, char *n, size_t len);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	char		*h;
	char		*n;

	i = 0;
	h = (char *)haystack;
	n = (char *)needle;
	if (ft_strlen(haystack) == 0 && ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (ft_strlen(haystack) == 0)
		return (0);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	return (find_needle(i, h, n, len));
}

static char	*find_needle(size_t i, char *h, char *n, size_t len)
{
	size_t	a;

	while (i < len && i < ft_strlen(h))
	{
		a = 0;
		if (n[a] == h[i + a])
		{
			while (n[a] && h[i + a])
			{
				if (n[a] != h[i + a] || (i + a) >= len)
					break ;
				a++;
			}
			if (n[a] == '\0')
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
