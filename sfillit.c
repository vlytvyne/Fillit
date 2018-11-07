
#include "fillit.h"

int		is_place(char **board, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (i2 < elem->height)
	{
		j = tmp;
		j2 = 0;
		while (elem->shape[i2][j2])
		{
			if (elem->shape[i2][j2] != EMPTY && board[i][j] != EMPTY)
				return (0);
			j++;
			j2++;
		}
		i++;
		i2++;
	}
	return (1);
}

void	clear(char **board, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (i2 < elem->height)
	{
		j = tmp;
		j2 = 0;
		while (elem->shape[i2][j2])
		{
			if (elem->shape[i2][j2] != EMPTY)
				board[i][j] = EMPTY;
			j++;
			j2++;
		}
		i++;
		i2++;
	}
}

char	**put(char **board, t_block *elem, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (i2 < elem->height)
	{
		j = tmp;
		j2 = 0;
		while (elem->shape[i2][j2])
		{
			if (elem->shape[i2][j2] != EMPTY)
				board[i][j] = elem->shape[i2][j2];
			j++;
			j2++;
		}
		i++;
		i2++;
	}
	return (ft_fillit(board, elem->next));
}

char	**ft_fillit(char **board, t_block *elem)
{
	int i;
	int j;

	i = 0;
	if (elem == NULL)
		return (board);
	while (i <= g_size - elem->height)
	{
		j = 0;
		while (j <= g_size - elem->width + 1)
		{
			if (is_place(board, elem, i, j))
			{
				if (put(board, elem, i, j))
					return (board);
				clear(board, elem, i, j);
			}
			j++;
		}
		i++;
	}
	if (elem->is_first == 1)
		return (ft_fillit(ft_update_board(board), elem));
	return (NULL);
}
