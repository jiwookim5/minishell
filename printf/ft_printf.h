/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:22:40 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/05/18 16:28:24 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
int		ft_printf(const char *format, ...);
int		ft_percent(const char *format, va_list ap, int error_check, int len);
int		ft_distinguish(va_list ap, const char format);
int		ft_decide_c(va_list arg);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_decide_p(va_list arg);
int		ft_decide_16_output(unsigned long long c, int *len);
int		ft_decide_s(va_list arg);
int		ft_nbr_len(int x);
int		ft_decide_d_i(va_list arg);
int		ft_putnbr_fd(int n, int fd);
int		ft_unsigned_len(unsigned int x);
int		ft_decide_u_output(unsigned int n);
int		ft_decide_u(va_list arg);
int		ft_decide_x(va_list arg);
int		ft_decide_upper_output(unsigned long long c, int *len);
int		ft_decide_xx(va_list arg);

#endif