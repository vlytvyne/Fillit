
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
	list = ft_block_new();
	list->shape[0] = ft_strdup("###");
	list->shape[1] = ft_strdup("#..");
	list->height = 2;
	list->width = 3;
	board = ft_fillit(board, list, list);
	return (0);
}
