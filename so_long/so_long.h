/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 21:00:16 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/07/21 18:41:18 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>

int main();


typedef struct s_game	t_game;


struct	s_game
{	int		empty;
	int		wall;
	int		collectible;
	int		out;
	int		exit;
	char	*position;
};
#endif

