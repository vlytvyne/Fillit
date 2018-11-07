/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extracter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:25:22 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/07 15:25:23 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	fill_tet(t_block *block, char **domino, char letter)
{
	int		d_x;
	int		d_y;
	int		b_x;
	int		b_y;

	d_y = 0;
	b_y = 0;
	while (b_y < 4)
	{
		d_x = 0;
		b_x = 0;
		while (b_x < 4)
		{
			if (SHAPE(b_x, b_y) == BLOCK || SHAPE(b_x, b_y) == EMPTY)
			{
				domino[d_y][d_x] = SHAPE(b_x, b_y) == BLOCK ? letter : EMPTY;
				d_x++;
			}
			b_x++;
		}
		if (d_x > 0)
			d_y++;
		b_y++;
	}
}

static char	**create_tet(t_block *block)
{
	char	**domino;
	int		i;

	i = 0;
	domino = (char**)malloc(sizeof(char*) * block->height);
	while (i < block->height)
	{
		domino[i] = (char*)malloc(sizeof(char) * (block->width + 1));
		domino[i][block->width] = '\0';
		i++;
	}
	return (domino);
}

static void	replace_block_with_tet(t_block *block, char **tet)
{
	int i;

	i = 0;
	while (i < 4)
		free((block->shape)[i++]);
	free(block->shape);
	block->shape = tet;
}

void		extract_tetrimino(t_block *block)
{
	static char	letter = 'A';
	char		**domino;

	domino = create_tet(block);
	fill_tet(block, domino, letter);
	replace_block_with_tet(block, domino);
	letter++;
}
