/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:05:57 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/01 14:34:26 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_write(unsigned int move)
{
	char	i;

	if (move / 10 > 0)
		move_write(move / 10);
	i = move % 10 + '0';
	write (1, &i, 1);
}

void	move_func(t_game *game)
{
	write(1, "move_count : ", 13);
	move_write(++game->move_count);
	write(1, "\n", 1);
}
