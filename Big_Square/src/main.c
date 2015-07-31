/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 22:59:59 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"
#include "ft.h"
#include "err.h"

#define BUF_SIZE (1024 * 300)

int		g_errno = 0;

void	ft_read(t_grid *grid)
{
	char	*str;
	size_t	j;

	j = 1;
	while (ft_getline(&str, grid->fd) && !g_errno)
	{
		if (j >= grid->height)
		{
			ft_errno(13);
			free(str);
			return ;
		}
		map_line(grid, str, j);
		free(str);
		j++;
	}
	free(str);
	if (j < grid->height)
		ft_errno(13);
}

int		read_file(char *path)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_errno(7));
	return (fd);
}

void	ft_execute(int fd)
{
	t_grid			*grid;
	t_point			point;

	grid = init_grid(fd);
	ft_set_params(grid);
	if (!g_errno)
		read_first_line(grid);
	if (!g_errno)
		ft_read(grid);
	if (!g_errno)
		test_full(grid);
	if (g_errno)
		ft_putstr("Map error\n");
	else
	{
		ft_remap(grid);
		point = find_max(grid);
		draw_square(grid, point.x, point.y, point.max);
		print_grid(grid);
	}
	if (fd > 0)
		close(fd);
	free_grid(grid);
}

int		main(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			if (fd == -1)
				ft_errno(8);
			if (!g_errno)
				ft_execute(fd);
			else
			{
				ft_putnbr(g_errno);
				ft_putstr("Map error\n");
			}
			i++;
		}
	}
	else
		ft_execute(STDIN_FILENO);
	return (0);
}
