/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:44:15 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 21:33:19 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "ft.h"

int		ft_cell_search(t_grid *grid, size_t x, size_t y)
{
	int res[3];

	if (!grid->g[y][x].index)
		return (0);
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	if (size > (grid->width - x) || size > (grid->height - y))
		return (0);
	if (x < (grid->width - 1))
		res[0] = (grid->g[y][x + 1].index);
	if (y < (grid->height - 1))
		res[1] = (grid->g[y + 1][x].index);
	if ((x < (grid->width - 1)) && (y < (grid->height - 1)))
		res[2] = (grid->g[y + 1][x + 1].index);
	return (ft_min(res, 3) + 1);

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
			ft_cell_increment(grid, i, j);
			i++;
		}
		j++;
	}
}
