/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:51:38 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/07 15:51:41 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	set_width(t_block *block)
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
}

static void	set_height(t_block *block)
{
	int x;
	int y;
	int marks;

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

void		set_dimensions(t_block *block)
{
	set_width(block);
	set_height(block);
}
