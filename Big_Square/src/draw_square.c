/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 18:29:20 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/31 15:23:48 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h" 

void	draw_square(t_grid *grid, size_t x, size_t y, size_t size)
{
	size_t i;
	size_t j;

	j = 0;
	while (j++ < size)
	{
		i = 0;
		while (i++ < size)
		{
			grid->g[(y + j - 1)][(x + i - 1)].cell = grid->plein;
			ft_strcpy(grid->g[(y + j - 1)][(x + i - 1)].color, KWHT);
		}
	}
}