/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:27:00 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 08:59:33 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "bsq.h"

t_grid		*get_grid(char *str)
{
	t_grid *grid;

	grid = get_param(str);
	return (grid);
}

int			fill_grid(t_grid *grid)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = grid->str;
	j = 0;
	while (j < grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (*str == '\n' || *str == '\0')
				return (errno(3));
			grid->grid[j][i].cell = *str;
			str++;
			i++;
		}
		if (*str != '\n')
			return (errno(3));
		str++;
		j++;
	}
	return (1);
}
