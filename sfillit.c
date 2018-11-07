
#include "fillit.h"

int		is_place(char **board, char **shape, int i, int j)
{
	int i2;
	int j2;
	int tmp;
	static int count;

	i2 = 0;
	tmp = j;
	count++;
	if (shape[0][0] == EMPTY)
	{
		//printf("i : %d, j : %d\n", i, j);
		//ft_print_board(board);
		tmp -= 1;
		// for (int k = 0; k < 2; k++)
			// ft_putendl(shape[k]);
	}
	while (shape[i2])
	{
		j = tmp;
		j2 = 0;
		while (shape[i2][j2])
		{
			if (shape[i2][j2] != EMPTY && board[i][j] != EMPTY)
			{
				if (count == 14)
				{
					printf("TYT = i : %d, j : %d\n\n", i, j);
				}
				return (0);
			}
			j++;
			j2++;
		}
		i++;
		i2++;
	}
	return (1);
}

void	clear(char **board, char **shape, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	if (shape[0][0] == EMPTY)
			tmp -= 1;
	while (shape[i2])
	{
		j = tmp;
		j2 = 0;
		while (shape[i2][j2])
		{
			if (shape[i2][j2] != EMPTY)
				board[i][j] = EMPTY;
			j++;
			j2++;
		}
		i++;
		i2++;
	}
}

char	**put(char **board, t_block *elem, int i, int j, t_block *list)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	if (elem->shape[0][0] == EMPTY)
			tmp -= 1;
	while (elem->shape[i2])
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
	return (ft_fillit(board, elem->next, list));
}

char	**ft_fillit(char **board, t_block *elem, t_block *list)
{
	int i;
	int j;

	i = 0;
	if (elem == NULL)
		return (board);
	while (i <= g_size - elem->height)
	{
		j = 0;
		while (j <= g_size - elem->width)
		{
			if (board[i][j] == '.' && is_place(board, elem->shape, i, j))
			{
					if (put(board, elem, i, j, list) == NULL)
						clear(board, elem->shape, i, j);
					else
						return (board);
			}
			j++;
		}
		i++;
	}
	if (elem == list)
		return (ft_fillit(ft_update_board(board), elem, list));
	return (NULL);
}
