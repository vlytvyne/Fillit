/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:49:21 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/07 14:52:18 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block	*block_new(void)
{
	t_block *tmp;

	tmp = (t_block *)malloc(sizeof(t_block));
	tmp->shape = (char **)malloc(sizeof(char *) * 4);
	tmp->width = 0;
	tmp->height = 0;
	tmp->next = NULL;
	tmp->is_first = 0;
	return (tmp);
}

void	error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	show_usage(void)
{
	ft_putstr("usage: ./fillit file_with_tetrominos\n");
	exit(1);
}
