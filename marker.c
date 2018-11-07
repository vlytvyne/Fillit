/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:55:12 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/07 14:55:15 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	mark_top(t_block *block)
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

static void	mark_right(t_block *block)
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

static void	mark_left(t_block *block)
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

static void	mark_bottom(t_block *block)
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

void		mark_block(t_block *block)
{
	mark_top(block);
	mark_bottom(block);
	mark_left(block);
	mark_right(block);
}
