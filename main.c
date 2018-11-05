
#include "fillit.h"

int		main(int ac, char **av)
{
	int i;
	int fd;
	t_block *list;

	i = 0;
	if (ac != 2)
		show_usage();
	fd = open(av[1], O_RDONLY);
	list = ft_get_blocks(fd);
	return (0);
}