/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:16:14 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/29 21:55:15 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "err.h"
#include "bsq.h"

void	read_first_line(t_grid *grid)
{
	char	*str;
	int		ret;
	char	buf;
	int		i;

	str = NULL;
	i = 0;
	while ((ret = read(grid->fd, buf, 1)) && str[i] && str[i] != '\n')
	{
		if (!ft_allowed_chars(grid, buf))
			return ;
		if (!str)
			str = malloc(sizeof(char) * 2);
		else
			str = ft_realloc(str, 1);
		str[i] = buf;
		i++;
		str[i] = '\0';
	}
	grid->width = i;
	grid->grid[0] = malloc(sizeof(t_cell) * i);
	i = -1;
	while (++i < grid->width)
	{
		grid->grid[0][i].cell = str[i];
		grid->grid[0][i].index = (str[i] == grid->obs) ? -1 : 0;	
	}
	free(str);
}
