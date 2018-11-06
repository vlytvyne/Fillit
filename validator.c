/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:03:38 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/05 15:03:44 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_block		*block_new(void)
{
	t_block *tmp;

	tmp = (t_block *)malloc(sizeof(t_block));
	tmp->shape = (char **)malloc(sizeof(char *) * 4);
	tmp->width = 0;
	tmp->height = 0;
	tmp->next = NULL;
	return (tmp);
}

t_block		*get_blocks(int fd)
{
	int		i;
	char	*check;
	t_block	*list;
	t_block *elem;

	list = block_new();
	elem = list;
	while (1)
	{
		i = 0;
		while (i < 4)
		{
			if (get_next_line(fd, &elem->shape[i]) <= 0)
				error(2);
			if (ft_strlen(elem->shape[i]) != 4)
				error(3);
			i++;
		}
		if (get_next_line(fd, &check) > 0)
		{
			if (*check)
				error(4);
			elem->next = block_new();
			elem = elem->next;
		}
		else
			break ;
	}
	return (list);
}
