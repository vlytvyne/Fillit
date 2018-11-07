
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
	t_block		*elem;

	g_size = 3;
	board = ft_create_board();
	//board[0][1] = BLOCK;
	list = ft_block_new();
	list->shape[0] = ft_strdup("AA");
	list->shape[1] = ft_strdup(".A");
	list->shape[2] = ft_strdup(".A");
	list->shape[3] = 0;
	list->height = 3;
	list->width = 2;
	list->next = ft_block_new();
	list->next->shape[0] = ft_strdup("C.");
	list->next->shape[1] = ft_strdup("CC");
	list->next->shape[2] = ft_strdup("C.");
	list->next->shape[3] = 0;
	list->next->height = 3;
	list->next->width = 2;
	list->next->next = ft_block_new();
	list->next->next->shape[0] = ft_strdup(".B.");
	list->next->next->shape[1] = ft_strdup("BBB");
	list->next->next->shape[2] = 0;
	list->next->next->height = 2;
	list->next->next->width = 3;
	list->next->next->next = ft_block_new();
	list->next->next->next->shape[0] = ft_strdup("DD");
	list->next->next->next->shape[1] = ft_strdup("DD");
	list->next->next->next->shape[2] = 0;
	list->next->next->next->height = 2;
	list->next->next->next->width = 2;
	printf("Original :\n");
	ft_print_board(board);
	printf("\n");
	board = ft_fillit(board, list, list);
	printf("Filled :\n");
	ft_print_board(board);
	return (0);
}
