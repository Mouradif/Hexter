/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:38:07 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/28 16:32:38 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		ft_cell_search(t_grid grid, size_t i, size_t j)
{
	char r;
	char dr;
	char d;
	char o;

	o = grid.obstacle;
	if (i >= (grid.taille - 1) || j >= (grid.taille - 1))
		return (0);
	else
	{
		r = grid.grid[j][i + 1].cell;
		dr = grid.grid[j + 1][i + 1].cell;
		d = grid.grid[j + 1][i].cell;
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

	o = grid->obstacle;
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
	int i;
	int j;

	j = 0;
	while (j < grid->size)
	{
		i = 0;
		while (i < grid->size)
		{
			if (ft_cell_search(grid, i , j))
				ft_cell_increment(grid, i, j);
		}
	}
}
