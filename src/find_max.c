/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 21:49:31 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 22:24:04 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_point find_max(t_grid *grid)
{
	t_point 		point;
	unsigned int 	i;
	unsigned int	j;

	j = 0;
	point.max = grid->g[j][0].index;
	point.x = 0;
	point.y = 0;
	while (j < grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (grid->g[j][i].index > point.max)
			{
				point.max = grid->g[j][i].index;
				point.x = i;
				point.y = j;
			}
			i++;
		}
		j++;
	}
	return (point);
}
