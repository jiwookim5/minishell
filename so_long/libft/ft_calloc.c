/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 09:18:29 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/03/16 15:54:00 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*a;

	a = (char *)malloc(sizeof(char) * (count * size));
	if (a == 0)
		return (0);
	ft_memset (a, 0, count * size);
	return (a);
}
