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

extern int g_size;

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

t_board					get_empty_board(int size);
t_board 				find_solution(t_board b, t_block *domino);
t_board					make_board_copy(t_board src);

char					**fillit(char **board, t_block *elem);

char					**create_board(void);
char					**update_board(char **board);
void					print_board(char **board);




t_block					*block_new(void);
void					show_usage(void);
void					error();
t_block					*get_valid_raw_blocks(int fd, int *num_tetriminos);
void					mark_block(t_block *block);
void					set_dimensions(t_block *block);
void					extract_tetrimino(t_block *block);

#endif
