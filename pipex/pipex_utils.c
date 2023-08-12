/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:33:06 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/12 20:38:34 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char *ft_route(char *path)
{
    int i;
    char *c;
    int j;

    i = 0;
    j = 0;
    while (path[i] == ':')
        i++;
    c = (char *)malloc(sizeof(char) * i + 1);
    if (!c)
        return(0);
    c[i] = '\0';
    i = 0;
    while(path[j] != ':')
    {
        c[i] = path[j];
        i++;
        j++;
    }
    return(c);
}
int ft_str_chr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] && str[i] != c)
        i++;
    if (str[i] == c)
        return(i);
    return(0);
}


char *path_join(char *path, char *cmd)
{
    char *c;
    int i;
    int j;

    c = (char *)malloc(sizeof(char) * (ft_str_chr(path, '\0') + ft_str_chr(cmd, '\0')+ 2));
    i = 0;
    j = 0;
    while(path[j] != '\0')
    {
        c[i] = path[j];
        i++;
        j++;
    }
    c[i] = '/';
    i++;
    j = 0;
    while (cmd[j])
    {

        c[i] = cmd[j];
        i++;
        j++;
    }
    c[i]= '\0';
    return(c);
    
}


char	*ft_str_dup (char *str, int n)
{
	char		*c;
	int		i;

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