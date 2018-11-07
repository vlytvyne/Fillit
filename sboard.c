
#include "fillit.h"

char        **create_board(void)
{
	char	**board;
	int		i;
	int		j;

	board = (char **)malloc(sizeof(char *) * g_size);
	i = 0;
	while (i < g_size)
	{
		j = 0;
		board[i] = ft_strnew(g_size);
		while (j < g_size)
		{
			board[i][j] = EMPTY;
			j++;
		}
		i++;
	}
	return (board);
}

char		**update_board(char **board)
{
	int		i;

	i = 0;
	while (i < g_size)
	{
		free(board[i]);
		i++;
	}
	free(board);
	g_size += 1;
	return (create_board());
}

void		print_board(char **board)
{
	int		i;

	i = 0;
	while (i < g_size)
	{
		ft_putendl(board[i]);
		i++;
	}
}