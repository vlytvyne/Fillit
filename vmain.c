/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:03:04 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/05 15:03:11 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <limits.h>

void	print_tet(t_block *block)
{
	int y;
	int x;

	x = 0;
	y = 0;
	while (y < block->height)
	{
		x = 0;
		while (x < block->width)
		{
			printf("%c", SHAPE(x, y));
			x++;
		}
		printf("\n");
		y++;
	}
}

void	extract_tetrimino(t_block *block)
{
	static char	letter = 'A';
	char	**domino;
	int		i;
	int		d_x;
	int		d_y;
	int		b_x;
	int		b_y;
	int		tet_started;

	d_x = 0;
	d_y = 0;
	b_x = 0;
	b_y = 0;
	tet_started = 0;
	i = 0;
	domino = (char**)malloc(sizeof(char*) * block->height);
	while (i < block->height)
	{
		domino[i] = (char*)malloc(sizeof(char) * (block->width + 1));
		domino[i][block->width] = '\0';
		i++;
	}
	while (b_y < 4)
	{
		d_x = 0;
		b_x = 0;
		while (b_x < 4)
		{
			if (SHAPE(b_x, b_y) == BLOCK || SHAPE(b_x, b_y) == EMPTY)
			{
				if (SHAPE(b_x, b_y) == BLOCK)
					domino[d_y][d_x] = letter;
				if (SHAPE(b_x, b_y) == EMPTY)
					domino[d_y][d_x] = EMPTY;
				tet_started = 1;
				d_x++;
			}
			b_x++;
		}
		if (tet_started)
			d_y++;
		b_y++;
	}
	i = 0;
	while (i < 4)
		free((block->shape)[i++]);
	free(block->shape);
	block->shape = domino;
	letter++;
}

void	mark_right(t_block *block)
{
	int x;
	int y;

	x = 3;
	while (x >= 0)
	{
		y = 0;
		while (y < 4)
		{	
			if (SHAPE(x, y) == BLOCK)
				return ;
			y++;
		}
		y = 0;
		while (y < 4)
		{	
			SHAPE(x, y) = MARK;
			y++;
		}
		x--;
	}
}

void	mark_left(t_block *block)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{	
			if (SHAPE(x, y) == BLOCK)
				return ;
			y++;
		}
		y = 0;
		while (y < 4)
		{	
			SHAPE(x, y) = MARK;
			y++;
		}
		x++;
	}
}

void	mark_bottom(t_block *block)
{
	int x;
	int y;

	y = 3;
	while (y >= 0)
	{
		x = 0;
		while (x < 4)
		{	
			if (SHAPE(x, y) == BLOCK)
				return ;
			x++;
		}
		x = 0;
		while (x < 4)
		{	
			SHAPE(x, y) = MARK;
			x++;
		}
		y--;
	}
}

void	set_dimensions(t_block *block)
{
	int x;
	int y;
	int marks;

	y = 0;
	while (y < 4)
	{
		marks = 0;
		x = 0;
		while (x < 4)
		{	
			if (SHAPE(x, y) == MARK)
				marks++;
			x++;
		}
		if (marks != 4)
		{
			block->width = 4 - marks;
			break ;
		}
		y++;
	}
	x = 0;
	while (x < 4)
	{
		marks = 0;
		y = 0;
		while (y < 4)
		{	
			if (SHAPE(x, y) == MARK)
				marks++;
			y++;
		}
		if (marks != 4)
		{
			block->height = 4 - marks;
			break ;
		}
		x++;
	}
}

void	mark_top(t_block *block)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{	
			if (SHAPE(x, y) == BLOCK)
				return ;
			x++;
		}
		x = 0;
		while (x < 4)
		{	
			SHAPE(x, y) = MARK;
			x++;
		}
		y++;
	}
}

void	error(int i)
{
	printf("Error : %d\n", i);
	exit(1);
}

int		main(int ac, char **av)
{
	int i;
	int fd;
	t_block *list;
	t_block *elem;

	i = 0;
	if (ac != 2)
		error(1);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error(1);
	list = get_valid_raw_blocks(fd);
	elem = list;
	while (elem)
	{
		mark_top(elem);
		mark_bottom(elem);
		mark_left(elem);
		mark_right(elem);
		set_dimensions(elem);
		extract_tetrimino(elem);
		print_tet(elem);
		printf("\n");
		elem = elem->next;
	}
	return (0);
}
