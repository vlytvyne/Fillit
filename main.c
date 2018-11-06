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

int		main(void)
{
	t_board board = get_empty_board(5);
	t_board board2 = board;
	t_block domino;

	board.board[0][0] = '1';
	board2 = make_board_copy(board);
	board2.board[0][0] = '2';
	free(board);
	print_board(board);
	print_board(board2);
}
