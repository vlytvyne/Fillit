/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:11:26 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/07 14:11:29 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

static int		count_neighbors(t_block *block, int x, int y)
{
	int neighbor_score;

	neighbor_score = 0;
	if (x + 1 < 4)
		if (SHAPE(x + 1, y) == BLOCK)
			neighbor_score++;
	if (x - 1 >= 0)
		if (SHAPE(x - 1, y) == BLOCK)
			neighbor_score++;
	if (y + 1 < 4)
		if (SHAPE(x, y + 1) == BLOCK)
			neighbor_score++;
	if (y - 1 >= 0)
		if (SHAPE(x, y - 1) == BLOCK)
			neighbor_score++;
	if (neighbor_score == 0)
		error();
	return (neighbor_score);
}

static void		valid_sequence(t_block *block)
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
			if (SHAPE(x, y) == BLOCK)
				neighbor_score += count_neighbors(block, x, y);
			x++;
		}
		y++;
	}
	if (neighbor_score != 6 && neighbor_score != 8)
		error();
}

static void		valid_blocks(t_block *block)
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
			if (SHAPE(x, y) != BLOCK && SHAPE(x, y) != EMPTY)
				error();
			if (SHAPE(x, y) == BLOCK)
				block_counter++;
			x++;
		}
		y++;
	}
	if (block_counter != 4)
		error();
}

static void		read_into_block(int fd, t_block *elem)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (get_next_line(fd, &elem->shape[i]) <= 0)
			error();
		if (ft_strlen(elem->shape[i]) != 4)
			error();
		i++;
	}
	valid_blocks(elem);
	valid_sequence(elem);
}

t_block			*get_valid_raw_blocks(int fd, int *num_tetriminos)
{
	char	*check;
	t_block	*list;
	t_block *elem;

	*num_tetriminos = 0;
	list = block_new();
	elem = list;
	while (1)
	{
		(*num_tetriminos)++;
		read_into_block(fd, elem);
		if (get_next_line(fd, &check) > 0)
		{
			if (*check)
				error();
			elem->next = block_new();
			elem = elem->next;
		}
		else
			break ;
	}
	if (*num_tetriminos > 26)
		error();
	return (list);
}
