/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:16:14 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 12:54:57 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"
#include "err.h"
#include "bsq.h"

void	read_first_line(t_grid *grid)
{
	char	*str;
	int		ret;
	size_t	i;

	str = ft_getline(grid->fd);
	grid->width = ft_strlen(str);
	grid->grid[0] = malloc(sizeof(t_cell) * grid->width);
	i = 0;
	while (i < grid->width)
	{
		if (!ft_allowed_chars(grid, str[i]))
			return ;
		grid->grid[0][i].cell = str[i];
		grid->grid[0][i].index = (str[i] == grid->obs) ? -1 : 0;
		i++;
	}
	free(str);
}
