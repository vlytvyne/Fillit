
#include "fillit.h"

int			ft_place(char **board, t_block *elem, int i, int j)
{
	board = NULL;
	elem = NULL;
	i = 0;
	j = 0;
	return (1);
}

char		**ft_fillit(char **board, t_block *elem, t_block *list)
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
				if (ft_place(board, elem, i , j)) // Должна проверить/поставить блок на карту
				{
					ft_print_board(board);
					return (ft_fillit(board, elem->next, list)); // Если поставить удалось пробуем ставить следующий блок
				}
			}
			j++;
		}
		i++;
	} 
	return (ft_fillit(ft_update_board(board), list, list)); // Если все клетки закончились увеличиваем размер доски
}