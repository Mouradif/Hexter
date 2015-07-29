/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:44:15 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 20:26:39 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"

int		ft_cell_search(t_grid *grid, size_t i, size_t j)
{
	char r;
	char dr;
	char d;
	char o;

	o = grid->obs;
	if (i >= (grid->width - 1) || j >= (grid->height - 1))
		return (0);
	else
	{
		r = grid->grid[j][i + 1].cell;
		dr = grid->grid[j + 1][i + 1].cell;
		d = grid->grid[j + 1][i].cell;
		if (r == o || dr == o || d == o)
			return (0);
		else
			return (1);
	}
}

void	ft_cell_increment(t_grid *grid, size_t i, size_t j)
{
	char ul;
	char o;

	o = grid->obs;
	grid->grid[j][i].index += 1;
	if (i > 0 && j > 0)
	{
		ul = grid->grid[i - 1][j - 1].cell;
		if (ul != o)
			ft_cell_increment(grid, (i - 1), (j - 1));
	}
}

void	ft_remap(t_grid *grid)
{
	size_t i;
	size_t j;

	j = 0;
	while (j < grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (ft_cell_search(*grid, i, j))
				ft_cell_increment(grid, i, j);
		}
	}
}
