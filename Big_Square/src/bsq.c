/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:37:59 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/31 09:23:49 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "bsq.h"
#include "err.h"
#include "ft.h"

int	map_line(t_grid *grid, char *str, size_t j)
{
	size_t i;

	if (j >= grid->height)
	{
		return (ft_errno(3));
	}
	grid->g[j] = malloc(grid->width * sizeof(t_cell));
	i = 0;
	while (i < grid->width)
	{
		if (!ft_allowed_chars(grid, str[i]))
			return (ft_errno(5));
		grid->g[j][i].cell = str[i];
		grid->g[j][i].index = (str[i] == grid->obs) ? 0 : 1;
		ft_strcpy(grid->g[j][i].color, ((grid->g[j][i].index) ? KGRN : KRED));
		i++;
	}
	return (0);
}
