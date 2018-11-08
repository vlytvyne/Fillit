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

int		fil_sqrt(int nb)
{
	int	root;

	if (nb == 0)
		return (0);
	root = 1;
	while (root * root < nb)
		root++;
	return (root);
}

void	get_ready(t_block *elem)
{
	while (elem)
	{
		mark_block(elem);
		set_dimensions(elem);
		extract_tetrimino(elem);
		elem = elem->next;
	}
}

int		main(int ac, char **av)
{
	int		fd;
	t_block *list;
	t_board	b;
	int		num_terminos;

	if (ac != 2)
		show_usage();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	list = get_valid_raw_blocks(fd, &num_terminos);
	if (close(fd) == -1)
		error();
	get_ready(list);
	list->is_first = 1;
	b.size = fil_sqrt(num_terminos);
	create_board(&b);
	fillit(&b, list);
	print_board(&b);
	return (0);
}
