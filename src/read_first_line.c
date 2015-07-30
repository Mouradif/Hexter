/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:16:14 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 12:46:27 by jlawson          ###   ########.fr       */
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
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 2);
	str[1] = '\0';
	while ((ret = read(grid->fd, (str + i), 1)) && str[i] && str[i] != '\n')
	{
		if (!ft_allowed_chars(grid, str[i]))
			return ;
		str = ft_realloc(str, 1);
	}
	grid->width = i;
	grid->grid[0] = malloc(sizeof(t_cell) * i);
	i = -1;
	while (++i < (int)grid->width)
	{
		grid->grid[0][i].cell = str[i];
		grid->grid[0][i].index = (str[i] == grid->obs) ? -1 : 0;
	}
	free(str);
}
