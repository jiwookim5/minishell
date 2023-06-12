/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_distinguish.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:36:12 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/05/18 16:24:08 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_distinguish(va_list ap, const char format)
{
	if (format == 'c')
		return (ft_decide_c(ap));
	else if (format == 'p')
		return (ft_decide_p(ap));
	else if (format == 's')
		return (ft_decide_s(ap));
	else if (format == 'd' || format == 'i')
		return (ft_decide_d_i(ap));
	else if (format == 'u')
		return (ft_decide_u(ap));
	else if (format == 'x')
		return (ft_decide_x(ap));
	else if (format == 'X')
		return (ft_decide_xx(ap));
	else
	{
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	return (0);
}
