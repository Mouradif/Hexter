/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_full.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 22:36:00 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 22:47:19 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct"
#include "err.h"

int	test_full(t_grid *grid)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			if (grid->g[j][i].index > 0)
				return ;
			i++;
		}
		j++;
	}
	errno(4);
}
