/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sfillit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:53:28 by okryzhan          #+#    #+#             */
/*   Updated: 2018/11/07 18:53:35 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_place(char **board, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (i2 < elem->height)
	{
		j = tmp;
		j2 = 0;
		while (elem->shape[i2][j2])
		{
			if (elem->shape[i2][j2] != EMPTY && board[i][j] != EMPTY)
				return (0);
			j++;
			j2++;
		}
		i++;
		i2++;
	}
	return (1);
}

void	clear(char **board, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (i2 < elem->height)
	{
		j = tmp;
		j2 = 0;
		while (elem->shape[i2][j2])
		{
			if (elem->shape[i2][j2] != EMPTY)
				board[i][j] = EMPTY;
			j++;
			j2++;
		}
		i++;
		i2++;
	}
}

int		put(t_board *b, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (i2 < elem->height)
	{
		j = tmp;
		j2 = 0;
		while (elem->shape[i2][j2])
		{
			if (elem->shape[i2][j2] != EMPTY)
				b->board[i][j] = elem->shape[i2][j2];
			j++;
			j2++;
		}
		i++;
		i2++;
	}
	return (fillit(b, elem->next));
}

int		fillit(t_board *b, t_block *elem)
{
	int i;
	int j;

	i = 0;
	if (elem == NULL)
		return (1);
	while (i <= b->size - elem->height)
	{
		j = 0;
		while (j <= b->size - elem->width + 1)
		{
			if (is_place(b->board, elem, i, j))
			{
				if (put(b, elem, i, j))
					return (1);
				clear(b->board, elem, i, j);
			}
			j++;
		}
		i++;
	}
	if (elem->is_first == 1)
		return (fillit(update_board(b), elem));
	return (0);
}
