/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:59:51 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/11 18:48:01 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_file	t_file;

struct s_file
{	
	int infile;
	int outfile;
};
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>



# endif