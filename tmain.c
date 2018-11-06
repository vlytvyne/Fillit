
#include "fillit.h"

int		g_size;

void	error(int i)
{
	printf("Error : %d\n", i);
	exit(1);
}

int		main(void)
{
	char		**board;
	t_block		*list;

	g_size = 5;
	board = ft_create_board();
	printf("size - %d\n", g_size);
	ft_print_board(board);
	board = ft_update_board(board);
	printf("size - %d\n", g_size);
	ft_print_board(board);
	list = ft_block_new();
	list->shape[0] = ft_strdup("###");
	list->shape[1] = ft_strdup("#..");
	list->height = 2;
	list->width = 3;
	ft_fillit(list, board);
	return (0);
}
