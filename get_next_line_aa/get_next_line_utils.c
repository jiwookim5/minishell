/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:43:43 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/04/05 14:42:59 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*res;
	char	*temp;

	i = ft_strlen(s1);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (res == 0)
		return (0);
	temp = res;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	*temp = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	char	*a;
	char	b;
	int		i;

	if (str == 0)
		return (0);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		s1_len;
	char		*res;
	size_t		s2_len;

	if (s1 == 0 || s2 == 0)
	{
		res = (char *)malloc(sizeof(char) + 1);
		res[0] = 0;
		return (res);
	}
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc(sizeof (char) * (s1_len + s2_len + 1));
	if (res == 0)
		return (0);
	ft_memcpy(res, s1, s1_len);
	ft_memcpy(res + s1_len, s2, s2_len);
	res[s1_len + s2_len] = 0;
	return (res);
}
