/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 17:10:30 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 18:59:47 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	fill_test_grid(t_grid *grid)
{
	size_t i;
	size_t j;

	j = 0;
	grid = malloc(sizeof(t_grid));
	grid->fd = 0;
	grid->obs = 'o';
	grid->vide = '.';
	grid->plein = 'x';
	grid->height = 5;
	grid->width = 10;
	grid->g = malloc(sizeof(t_cell*) * grid->height);
	while (j < grid->height)
	{
		grid->g[j] = malloc(sizeof(t_cell) * grid->width);
		i = 0;
		while (i < grid->width)
		{
			grid->g[j][i].cell = '.';
			grid->g[j][i].index = 0;
			i++;
		}
		j++;
	}
}

