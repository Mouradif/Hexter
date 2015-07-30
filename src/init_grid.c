/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:55:29 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 19:42:45 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "bsq.h"

#define NOT_EQUAL(a, b, c) (a != b && b != c && c != a)

int				is_printable(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}

t_grid			*init_grid(int fd)
{
	t_grid	*grid;

	grid = malloc(sizeof(t_grid));
	grid->fd = fd;
	grid->g = NULL;
	return (grid);
}

void			free_grid(t_grid *grid)
{
	unsigned int i;
	if (grid)
	{
		if (grid->g)
		{
			i = 0;
			while (i < grid->height)
			{
				if (grid->g[i])
					free(grid->g[i]);
				i++;
			}
			free(grid->g);
		}
		free(grid);
	}
}
