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

int		g_size = 2;

int		main(int ac, char **av)
{
	int		fd;
	t_block *list;
	t_block *elem;
	char	**board;
	int		num_terminos;

	if (ac != 2)
		show_usage();
	if ((fd = open(av[1], O_RDONLY)) == -1)
		error();
	list = get_valid_raw_blocks(fd, &num_terminos);
	elem = list;
	if (close(fd) == -1)
		error();
	while (elem)
	{
		mark_block(elem);
		set_dimensions(elem);
		extract_tetrimino(elem);
		elem = elem->next;
	}
	list->is_first = 1;
	board = create_board();
	board = fillit(board, list);
	print_board(board);
	return (0);
}
