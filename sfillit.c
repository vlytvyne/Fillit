
#include "fillit.h"

int		is_place(char **board, char **shape, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	while (shape[i2])
	{
		j = tmp;
		j2 = 0;
		while (shape[i2][j2])
		{
			if (shape[i2][j2] != EMPTY && board[i][j] != EMPTY)
				return (0);
			j++;
			j2++;
		}
		i++;
		i2++;
	}
	return (1);
}

void	put(char **board, char **shape, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	printf("i : %d, j : %d\n", i, j);
	while (shape[i2])
	{
		j = tmp;
		j2 = 0;
		while (shape[i2][j2])
		{
			if (shape[i2][j2] != EMPTY)
				board[i][j] = shape[i2][j2];
			j++;
			j2++;
		}
		i++;
		i2++;
	}
}

void	clear(char **board, char **shape, int i, int j)
{
	int i2;
	int j2;
	int tmp;

	i2 = 0;
	tmp = j;
	printf("i : %d, j : %d\n", i, j);
	while (shape[i2])
	{
		j = tmp;
		j2 = 0;
		while (shape[i2][j2])
		{
			if (shape[i2][j2] == BLOCK)
				board[i][j] = EMPTY;
			j++;
			j2++;
		}
		i++;
		i2++;
	}
}

char	**ft_fillit(char **board, t_block *elem, t_block *list)
{
	int i;
	int j;

	i = 0;
	if (elem == NULL) // Если блоки закончились - мы их все поставили - Ура
		return (board);
	while (i <= g_size - elem->height)
	{
		j = 0;
		while (j <= g_size - elem->width)
		{
			if (board[i][j] == '.') // Если не удалось поставить - пробуем другую клетку
			{
				if (is_place(board, elem->shape, i, j))
				{
					printf("is_place - ok\n");
					put(board, elem->shape, i, j);
					return (ft_fillit(board, elem->next, list));
				}
				else
				{
					printf("is_place - ko\n");
				}
			}
			j++;
		}
		i++;
	} 
	return (ft_fillit(ft_update_board(board), list, list)); // Если все клетки закончились увеличиваем размер доски
}
