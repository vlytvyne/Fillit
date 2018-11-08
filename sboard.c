/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sboard.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okryzhan <okryzhan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:53:51 by okryzhan          #+#    #+#             */
/*   Updated: 2018/11/07 18:53:52 by okryzhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		create_board(t_board *b)
{
	int		i;
	int		j;

	MALCH((b->board = (char **)malloc(sizeof(char *) * b->size)));
	i = 0;
	while (i < b->size)
	{
		j = 0;
		MALCH((b->board[i] = ft_strnew(b->size)));
		while (j < b->size)
		{
			b->board[i][j] = EMPTY;
			j++;
		}
		i++;
	}
}

t_board		*update_board(t_board *b)
{
	int		i;

	i = 0;
	while (i < b->size)
	{
		free(b->board[i]);
		i++;
	}
	free(b->board);
	b->size += 1;
	create_board(b);
	return (b);
}

void		print_board(t_board *b)
{
	int		i;

	i = 0;
	while (i < b->size)
	{
		ft_putendl(b->board[i]);
		i++;
	}
}
