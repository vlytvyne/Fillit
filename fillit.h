
#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"

typedef struct	s_tetromino
{
	char				**shape;
	int					width;
	int					height;
	struct s_tetromino	*next;
}				t_block;

t_block			*ft_get_blocks(int fd);
void			show_usage(void);

#endif