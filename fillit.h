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

# define EMPTY .
# define BLOCK #

#include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

extern int				g_size;

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

t_block					*ft_block_new(void);
t_block					*ft_get_blocks(int fd);

char					**ft_fillit(char **board, t_block *elem, t_block *list);

char					**ft_create_board(void);
char					**ft_update_board(char **board);
void					ft_print_board(char **board);

void					error(int i);

#endif
