/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 18:54:37 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 20:21:02 by mkejji           ###   ########.fr       */
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
#include "test.h"

#define BUF_SIZE (1024 * 300)

int		g_errno = 0;

void	ft_read(t_grid *grid)
{
	char	*str;
	size_t	j;

	j = 1;
	while (ft_getline(&str, grid->fd))
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
	if (j < grid->height)
		ft_errno(13);
}
/*
   char	*read_file(char *path)
   {
   char	*buf;
   int		fd;

   fd = open(path, O_RDONLY);
   if (fd == -1)
   return (v_errno(7));
   ft_read();
   if (close(fd) == -1)
   return (v_errno(8));
   return (buf);
   }
   */
int		main(void)
{
	t_grid	*grid;

	grid = init_grid(STDIN_FILENO);
	ft_set_params(grid);
	if (!g_errno)
		read_first_line(grid);
	if (!g_errno)
		ft_read(grid);
	if (!g_errno)
	{
		ft_remap(grid);
	}	
	if (g_errno)
	{
		ft_putnbr(g_errno);
		ft_putstr("erreur\n");
	}
	else
		print_index(grid);
	free_grid(grid);
	return (0);
}
