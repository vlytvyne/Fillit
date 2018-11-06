/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:04:05 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/05 15:04:09 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define EMPTY '.'
# define BLOCK '#'

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct			s_tetromino
{
	char				**shape;
	int					width;
	int					height;
	struct s_tetromino	*next;
}						t_block;

typedef struct			s_board
{
	char				**board;
	int					size;
}						t_board;

t_block					*ft_get_blocks(int fd);
void					show_usage(void);
void					print_board(t_board b);
t_board					get_empty_board(int size);
t_board 				find_solution(t_board b, t_block *domino);
t_board					make_board_copy(t_board src);

#endif
