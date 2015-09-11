/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 18:29:20 by mkejji            #+#    #+#             */
/*   Updated: 2015/09/12 17:21:19 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"

void	draw_square(t_grid *grid, t_point point)
{
	size_t i;
	size_t j;

	j = 0;
	while (j < point.max)
	{
		i = 0;
		while (i < point.max)
		{
			grid->g[(point.y + j)][(point.x + i)].cell = grid->plein;
			ft_strcpy(grid->g[(point.y + j)][(point.x + i)].color, KWHT);
			i++;
		}
		j++;
	}
}
