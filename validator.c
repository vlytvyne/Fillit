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

t_block		*ft_block_new(void)
{
	t_block *tmp;

	tmp = (t_block *)malloc(sizeof(t_block));
	tmp->shape = (char **)malloc(sizeof(char *) * 4);
	tmp->width = 0;
	tmp->height = 0;
	tmp->next = NULL;
	return (tmp);
}

void		ft_error(void)
{
	ft_putendl("Error");
	exit(1);
}

t_block		*ft_get_blocks(int fd)
{
	int		i;
	int		ret;
	char	*check;
	t_block	*list;
	t_block *elem;

	list = ft_block_new();
	elem = list;
	while (1)
	{
		i = 0;
		while(i < 4)
		{
			if (get_next_line(fd, &elem->shape[i]) <= 0)
				ft_error();
			if (ft_strlen(elem->shape[i]) != 4)
				ft_error();
		i++;
		}
		if ((ret = get_next_line(fd, &check)))
		{
			if (*check != '\n')
				ft_error();
			elem->next = ft_block_new();
			elem = elem->next;
		}
		if (ret == 0)
			break ;
	}
	return (list);
}
