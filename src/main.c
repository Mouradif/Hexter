/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 22:18:59 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"
#include "ft.h"

#define BUF_SIZE (1024 * 300)

int		g_errno = 0;

void	ft_read_next(t_grid *grid, char buf, size_t *i, size_t *j)
{
	if (buf == '\n')
	{
		(*j)++;
		*i = 0;
	}
	else
	{
		if (*i >= grid->width)
			errno(3);
		else
		{
			grid->grid[*j][*i].cell = buf;
			grid->grid[*j][*i].index = (buf == grid->obs) ? -1 : 0;
			i++;
		}
	}
}

void	ft_read(t_grid *grid)
{
	char	buf;
	size_t	i;
	size_t	j;
	int		err;

	i = 0;
	j = 1;
	while ((err = read(grid->fd, buf, len)))
	{
		if (err == -1)
			errno(12);
		if (g_errno)
			return ;
		else
		{
			if (buf == '\n' && i != grid->width)
				errno(3);
			else if (!ft_allowed_chars(grid, buf))
				return ;
			else
				ft_read_next(grid, buf, &i, &j);
		}
	}
}

char	*read_file(char *path)
{
	char	*buf;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (v_errno(7));
	buf = ft_read(fd);
	if (close(fd) == -1)
		return (v_errno(8));
	return (buf);
}

int		main(int ac, char **av)
{
	char	*str;
	int		i;
	t_grid	*grid;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			str = read_file(av[i]);
			ft_putstr(str);
			free(str);
		}
	}
	else
	{
		grid = init_grid(STDIN_FILENO);
		set_params(grid)
		read_first_line(grid);
		ft_read(grid);
		print_grid(grid);
	}
	return (0);
}
