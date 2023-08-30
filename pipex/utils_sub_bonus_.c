/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sub_bonus_.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:51:36 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/26 15:35:41 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	write(1, "error\n", 7);
	exit(1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			a;
	unsigned char	*a1;
	unsigned char	*a2;

	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	if (n <= 0)
		return (0);
	a = 0;
	while (a1[a] != '\0' && a2[a] != '\0' && a < n - 1)
	{
		if (a1[a] != a2[a])
			break ;
		a++;
	}
	return (a1[a] - a2[a]);
}

int	ft_str_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (0);
}

char	*ft_str_dup(char *str, int n)
{
	char		*c;
	int			i;

	i = 0;
	c = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		c[i] = str[i];
		i++;
	}
	c[n] = 0;
	return (c);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			a;
	unsigned char	*a1;
	unsigned char	*a2;

	if (s1 == NULL)
		exit (1);
	a1 = (unsigned char *) s1;
	a2 = (unsigned char *) s2;
	a = 0;
	while (a1[a] != '\0' && a2[a] != '\0')
	{
		if (a1[a] != a2[a])
			break ;
		a++;
	}
	return (a1[a] - a2[a]);
}
