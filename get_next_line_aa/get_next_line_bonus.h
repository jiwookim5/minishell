/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:49:32 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/04/06 21:42:31 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPENMAX 49152

size_t		ft_strlen(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *str, int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);

#endif
