/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:44:15 by jlawson           #+#    #+#             */
/*   Updated: 2015/09/12 17:21:27 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "ft.h"
#include "test.h"

unsigned int	ft_cell_search(t_grid *grid, size_t x, size_t y)
{
	unsigned int res[3];

	if (!grid->g[y][x].index)
		return (0);
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	if (x < (grid->width - 1))
		res[0] = (grid->g[y][x + 1].index);
	if (y < (grid->height - 1))
		res[1] = (grid->g[y + 1][x].index);
	if ((x < (grid->width - 1)) && (y < (grid->height - 1)))
		res[2] = (grid->g[y + 1][x + 1].index);
	return (ft_min(res, 3) + 1);
}

t_point	ft_remap(t_grid *grid)
{
	size_t	i;
	size_t	j;
	t_point	res;

	j = grid->height;
	res.max = 0;
	while (j > 0)
	{
		j--;
		i = grid->width;
		while (i > 0)
		{
			i--;
			grid->g[j][i].index = ft_cell_search(grid, i, j);
			if (grid->g[j][i].index >= res.max)
			{
				res.max = grid->g[j][i].index;
				res.x = i;
				res.y = j;
			}
		}
	}
	return (res);
}
