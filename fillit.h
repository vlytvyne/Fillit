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
# define MARK '@'
# define SHAPE(x, y) block->shape[y][x]

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct			s_tetromino
{
	char				**shape;
	int					width;
	int					height;
	int					is_first;
	struct s_tetromino	*next;
}						t_block;

typedef struct			s_board
{
	char				**board;
	int					size;
}						t_board;

int						fillit(t_board *b, t_block *elem);
int						fil_sqrt(int nb);

void					create_board(t_board *b);
t_board					*update_board(t_board *b);
void					print_board(t_board *b);

t_block					*block_new(void);
void					show_usage(void);
void					error();
t_block					*get_valid_raw_blocks(int fd, int *num_tetriminos);
void					mark_block(t_block *block);
void					set_dimensions(t_block *block);
void					extract_tetrimino(t_block *block);

#endif
