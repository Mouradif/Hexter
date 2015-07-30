/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 14:48:31 by jlawson          ###   ########.fr       */
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

void	map_line();

void	ft_read(t_grid *grid)
{
	char	buf;
	char	*str;
	size_t	j;
	int		err;

	j = 1;
	while ((str = ft_getline(grid->fd)))
	{
		if (j >= grid->height)
		{
			errno(13);
			free(str);
			return ;
		}
		map_line(grid, str, j);
		free(str);
		j++;
	}
	if (j < grid->height)
		errno(13);
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
	read_first_line(grid);
	ft_read(grid);
	if (errno)
		ft_putstr("erreur\n");
	else
		print_grid(grid);
	return (0);
}
