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
	list = ft_get_blocks(fd);
	elem = list;
	while (elem)
	{
		for (int i = 0; i < 4; i++)
			printf("%s\n", elem->shape[i]);
		if (elem->next)
			printf("\n");
		elem = elem->next;
	}
	return (0);
}
