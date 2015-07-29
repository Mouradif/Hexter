/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:55:29 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 08:57:49 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "bsq.h"

#define NOT_EQUAL(a, b, c) (a != b && b != c && c != a)

size_t			size_line(char *str)
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
	if (i == size_l - 3 && ft_test_foreach((str + i), 3, &is_printable)
			&& NOT_EQUAL(str[i], str[i + 1], str[i + 2]))
		return (init_grid(size, str, i));
	else
		return (NULL);
}

t_cell			**malloc_grid(size_t height, size_t width)
{
	t_cell	**grid;
	size_t	i;
	size_t	j;

	grid = malloc(sizeof(t_cell**));
	if (!(grid))
		return (NULL);
	j = 0;
	while (j < height)
	{
		i = 0;
		grid[j] = malloc(sizeof(t_cell*));
		if (!(grid[j]))
			return (NULL);
		while (i < width)
		{	
			grid[j][i].index = 0;
			i++;
		}
		j++;
	}
	return (grid);
}

t_grid			*init_grid(size_t size, char *str, size_t pointer_char)
{
	t_grid	*grid;
	size_t	i;
	char	*start_str;

	start_str = str + pointer_char + 4;
	i = size_line(start_str);
	grid = malloc(sizeof(t_grid));
	if (grid)
	{
		grid->height = size;
		grid->width = i;
		grid->str = start_str;
		grid->vide = str[pointer_char];
		grid->obs = str[pointer_char + 1];
		grid->plein = str[pointer_char + 2];
		grid->grid = malloc_grid(size, i);
		if (!(grid->grid))
			return (v_errno(6));
		return (grid);
	}
	else
		return (v_errno(6));
}
