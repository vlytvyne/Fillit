/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:13:25 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/05 16:13:29 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_board(t_board b)
{
	int i;

	i = 0;
	while (i < b.size)
	{
		ft_putstr(b.board[i]);
		ft_putchar('\n');
		i++;
	}
}

t_board	get_empty_board(int size)
{
	t_board b;
	int 	i;
	int		j;

	i = 0;
	b.size = size;
	b.board = (char**)malloc(size * sizeof(char*));
	while (i < size)
	{
		j = 0;
		b.board[i] = ft_strnew(size);
		while (j < size)
			b.board[i][j++] = EMPTY;
		i++;
	}
	return (b);
}

t_board	make_board_copy(t_board src)
{
	t_board b;
	int 	i;
	int		j;

	i = 0;
	b.size = src.size;
	b.board = (char**)malloc(src.size * sizeof(char*));
	while (i < src.size)
	{
		j = 0;
		b.board[i] = ft_strnew(src.size);
		while (j < src.size)
		{
			b.board[i][j] = src.board[i][j];
			j++;
		}
		i++;
	}
	return (b);
}

t_board find_solution(t_board b, t_block *domino)
{
	int		b_x;
	int		b_y;
	int		d_x;
	int		d_y;
	t_block before_inserting;

	b_x = 0;
	b_y = 0;
	d_x = 0;
	d_y = 0;
	while (d_y < domino->height)
	{
		d_x = 0;
		while (d_x < domino->width)
		{
			if (domino->shape[d_y][d_x] != EMPTY)
				if (b.board[b_y][b_x] == EMPTY)
					b.board[b_y][b_x] = domino->shape[d_y][d_x];
				else
					printf("No space");
			b_x++;
			d_x++;
		}
		b_x++;
		d_y++;
	}
	return (b);
}
