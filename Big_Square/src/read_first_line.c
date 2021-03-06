/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_first_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 19:16:14 by mkejji            #+#    #+#             */
/*   Updated: 2015/09/12 18:02:04 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"
#include "ft.h"
#include "err.h"
#include "bsq.h"

void	read_first_line(t_grid *grid)
{
	char	*str;
	size_t	i;

	i = ft_getline(&str, grid->fd);
	if (!i)
	{
		ft_errno(1);
		free(str);
		return ;
	}
	grid->width = i;
	grid->g[0] = malloc(sizeof(t_cell) * grid->width);
	i = 0;
	while (i < grid->width)
	{
		if (!ft_allowed_chars(grid, str[i]))
		{
			ft_errno(5);
			free(str);
			return ;
		}
		grid->g[0][i].cell = str[i];
		grid->g[0][i].index = (str[i] == grid->obs) ? 0 : 1;
		ft_strcpy(grid->g[0][i].color, ((grid->g[0][i].index) ? KGRN : KRED));
		i++;
	}
	free(str);
}
