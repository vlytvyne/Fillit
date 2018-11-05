/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlytvyne <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:03:38 by vlytvyne          #+#    #+#             */
/*   Updated: 2018/11/05 15:03:44 by vlytvyne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

t_block		*ft_block_new(void)
{
	t_block *tmp;

	tmp = (t_block *)malloc(sizeof(t_block));
	tmp->shape = (char **)malloc(sizeof(char *) * 4);
	tmp->width = 0;
	tmp->height = 0;
	tmp->next = NULL;
	return (tmp);
}

size_t		ft_len_char(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		if (s[len] != '.' && s[len] != '#')
			return (0);
		len++;
	}
	return (len);
}

void		ft_cut(char **shape)
{
	int		i;
	int		start;
	int		end;
	char	*c;

	i = 0;
	start = 5;
	end = 0;
	while (i < 4)
	{
		if ((c = ft_strchr(shape[i], '#')))
		{
			start = start > c - shape[i] ? start = c - shape[i] : start;
			c = ft_strrchr(shape[i], '#');
			end = end < c - shape[i] ? end = c - shape[i] : end;
			printf("start : %d end : %d\n", start, end);
		}
		else
		{
			//delete row
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		shape[i][end + 1] = '\0';
		ft_strcpy(shape[i], &shape[i][start]);
		i++;
	}
}

t_block		*ft_validate(t_block *list)
{
	t_block *elem;

	elem = list;
	while (elem)
	{
		ft_cut(elem->shape);
		elem = elem->next;
	}
	return (list);
}

t_block		*ft_get_blocks(int fd)
{
	int		i;
	int		ret;
	char	*check;
	t_block	*list;
	t_block *elem;

	list = ft_block_new();
	elem = list;
	while (1)
	{
		i = 0;
		while (i < 4)
		{
			if (get_next_line(fd, &elem->shape[i]) <= 0)
				error(2);
			if (ft_len_char(elem->shape[i]) != 4)
				error(3);
			i++;
		}
		if ((ret = get_next_line(fd, &check)) > 0)
		{
			if (*check)
				error(4);
			elem->next = ft_block_new();
			elem = elem->next;
		}
		else
			break ;
	}
	return (ft_validate(list));
}
