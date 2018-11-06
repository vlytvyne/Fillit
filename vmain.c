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
			printf("%c", (block->shape)[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	extract_tetrimino(t_block *block)
{
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
		//printf("----WHILE B_Y: %d D_Y: %d----\n", b_y, d_y);	
		while (b_x < 4)
		{
		//	printf("WHILE B_X: %d D_X: %d\n", b_x, d_x);
			if (block->shape[b_y][b_x] == BLOCK || block->shape[b_y][b_x] == EMPTY)
			{
				//printf("WSTAVIT'\n");
				domino[d_y][d_x] = block->shape[b_y][b_x];
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
}

void	cut_right(t_block *block)
{
	int x;
	int y;

	x = 3;
	while (x >= 0)
	{
		y = 0;
		while (y < 4)
		{	
			if (block->shape[y][x] == BLOCK)
				return ;
			y++;
		}
		y = 0;
		while (y < 4)
		{	
			block->shape[y][x] = SUB;
			y++;
		}
		x--;
	}
}

void	cut_left(t_block *block)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{	
			if (block->shape[y][x] == BLOCK)
				return ;
			y++;
		}
		y = 0;
		while (y < 4)
		{	
			block->shape[y][x] = SUB;
			y++;
		}
		x++;
	}
}

void	cut_bottom(t_block *block)
{
	int x;
	int y;

	y = 3;
	while (y >= 0)
	{
		x = 0;
		while (x < 4)
		{	
			if (block->shape[y][x] == BLOCK)
				return ;
			x++;
		}
		x = 0;
		while (x < 4)
		{	
			block->shape[y][x] = SUB;
			x++;
		}
		y--;
	}
}

void	cut_top(t_block *block)
{
	int x;
	int y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{	
			if (block->shape[y][x] == BLOCK)
				return ;
			x++;
		}
		x = 0;
		while (x < 4)
		{	
			block->shape[y][x] = SUB;
			x++;
		}
		y++;
	}
}

void	set_height(t_block *block)
{
	int x;
	int y;
	int left_corner;
	int right_corner;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{	
			if (block->shape[y][x] == BLOCK)
			{
				left_corner = y;
				y = 100;
				break;
			}
			x++;
		}
		y++;
	}
	y = 3;
	x = 3;
	while (y >= 0)
	{
		x = 3;
		while (x >= 0)
		{	
			if (block->shape[y][x] == BLOCK)
			{
				right_corner = y;
				y = -100;
				break;
			}
			x--;
		}
		y--;
	}
	block->height = right_corner - left_corner + 1;
}

void	set_width(t_block *block)
{
	int x;
	int y;
	int left_corner;
	int right_corner;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{	
			if (block->shape[y][x] == BLOCK)
			{
				left_corner = x;
				x = 100;
				break;
			}
			y++;
		}
		x++;
	}
	y = 3;
	x = 3;
	while (x >= 0)
	{
		y = 3;
		while (y >= 0)
		{	
			if (block->shape[y][x] == BLOCK)
			{
				right_corner = x;
				x = -100;
				break;
			}
			y--;
		}
		x--;
	}
	block->width = right_corner - left_corner + 1;
}

int		count_neighbors(t_block *block, int x, int y)
{
	int neighbor_score;

	neighbor_score = 0;
	if (x + 1 < 4)
		if (block->shape[y][x + 1] == BLOCK)
			neighbor_score++;
	if (x - 1 >= 0)
		if (block->shape[y][x - 1] == BLOCK)
			neighbor_score++;
	if (y + 1 < 4)
		if (block->shape[y + 1][x] == BLOCK)
			neighbor_score++;
	if (y - 1 >= 0)
		if (block->shape[y - 1][x] == BLOCK)
			neighbor_score++;
	if (neighbor_score == 0)
		error(8);
	return (neighbor_score);
}

void	valid_sequence(t_block *block)
{
	int x;
	int y;
	int	neighbor_score;

	x = 0;
	y = 0;
	neighbor_score = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{	
			if (block->shape[y][x] == BLOCK)
				neighbor_score += count_neighbors(block, x, y);					
			x++;
		}
		y++;
	}
	if (neighbor_score != 6 && neighbor_score != 8)
		error(9);
}

void	valid_blocks(t_block *block)
{
	int x;
	int y;
	int block_counter;

	x = 0;
	y = 0;
	block_counter = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{	
			if (block->shape[y][x] != BLOCK && block->shape[y][x] != EMPTY)
				error(7);
			if (block->shape[y][x] == BLOCK)
				block_counter++;
			x++;
		}
		y++;
	}
	if (block_counter != 4)
		error(5);
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
	list = get_blocks(fd);
	elem = list;
	while (elem)
	{
		valid_blocks(elem);
		valid_sequence(elem);
		set_height(elem);
		set_width(elem);
		cut_top(elem);
		cut_bottom(elem);
		cut_left(elem);
		cut_right(elem);
		extract_tetrimino(elem);
		// for (int i = 0; i < 4; i++)
		// 	printf("%s\n", elem->shape[i]);
		// if (elem->next)
		// 	printf("\n");
		print_tet(elem);
		printf("\n");
		elem = elem->next;
	}
	return (0);
}
