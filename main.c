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



int		main(int ac, char **av)
{
	int i;
	int fd;
	t_block *list;

	i = 0;
	if (ac != 2)
		show_usage();
	fd = open(av[1], O_RDONLY);
	list = ft_get_blocks(fd);
	return (0);
}
