/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwkim2 <jiwkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:17:52 by jiwkim2           #+#    #+#             */
/*   Updated: 2023/08/03 17:11:18 by jiwkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv)
{
    t_struct arg;
    
    if (argc == 5)
    {
        if (access(argv[1], R_OK) == 0)
        {
            arg.infile = open(argv[1], O_RDONLY);  
            printf("%d\n", arg.infile);
        }
        if (access(argv[4], W_OK) == 0)
        {
            arg.outfile = open(argv[4], O_WRONLY);
            printf("fd2 : %d\n", arg.outfile);
        }
        else
            printf("error\n");
        
    }
    return (0);
}