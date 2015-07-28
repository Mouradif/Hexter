/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:55:29 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/28 18:29:53 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "bsq.h"

#define NOT_EQUAL(a, b, c) (a != b && b != c && c != a)

t_grid			*get_param(char *str)
{
	size_t	i;
	size_t	size_l;
	size_t	size;

	i = 0;
	size_l = size_line(str);
	if (size_l < 4 && !(*str >= '1' && *str <= '9'))
		return (NULL);
	size = 0;
	while (i < size_l - 3 && str[i] >= '0' && str[i] <= '9')
	{
		size = size * 10 + str[i] - '0';
		i++;
	}
	if (i == size_l - 3 && ft_foreach((str + i), 3, &is_printable)
			&& NOT_EQUAL(str[i], str[i + 1], str[i + 2]))
		return (init_grid(size, str[i], str[i + 1], str[i + 2]));
	else
		return (NULL);
}

t_grid			*init_grid(size_t size, char *str, size_t pointer_char)
{
	t_grid	*grid;
	size_t	i;

	grid = malloc(sizeof(t_grid));
	if (grid)
	{
		grid->size = size;
		grid->str = str;
		grid->vide = str[pointer_char];
		grid->obstacle = str[pointer_char + 1];
		grid->plein = str[pointer_char + 2];
		grid->grid = malloc(size * sizeof(t_cell *));
		i = 0;
		if (grid->grid)
		{
			while (i < size)
			{
				grid->grid[i] = malloc(size * sizeof(t_cell));
				i++;
			}
		}
	}
	return (grid);
}

size_t	size_line(char *str)
{
	size_t ret;

	ret = 0;
	while (str[ret] && str[ret] != '\n')
		ret++;
	return (ret);
}

int				is_printable(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}
