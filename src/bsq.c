/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:37:59 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 18:55:56 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "bsq.h"
#include "err.h"

int	map_line(t_grid *grid, char *str, size_t j)
{
	size_t i;

	if (j >= grid->height)
	{
		return (errno(3));
	}
	grid->g[j] = malloc(grid->width * sizeof(t_cell));
	i = 0;
	while (i < grid->width)
	{
		if (!ft_allowed_chars(grid, str[i]))
			return (errno(5));
		grid->g[j][i].cell = str[i];
		grid->g[j][i].index = (str[i] == grid->obs) ? 0 : 1;
		i++;
	}
	return (0);
}
