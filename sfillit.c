
#include "fillit.h"

int			ft_place(char **board, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	if (i2 < elem->height)
	{
		if (j2 < elem->width)
		{

		}
	}
}

char		**ft_fillit(char **board, t_block *elem)
{
	int i;
	int j;

	i = 0;
	while (i <= g_size - elem->height)
	{
		j = 0;
		while (j <= g_size - elem->width)
		{
			if (board[i][j] == '.')
			{
				if (ft_place(board, elem, i , j))
				{
					ft_print_board(board);
				}
			}
			j++;
		}
		i++;
	}
	return (board);
}