/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 19:21:33 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 19:22:48 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"

void	print_index(t_grid *grid)
{
	size_t i;
	size_t j;

	ft_putnbr(grid->width);
	ft_putchar('x');
	ft_putnbr(grid->height);
	ft_putstr("\t[");
	ft_putchar(grid->vide);
	ft_putstr("] [");
	ft_putchar(grid->obs);
	ft_putstr("] [");
	ft_putchar(grid->plein);
	ft_putstr("]\n");
	j = 0;
	while (j < grid->height)
	{
		i = 0;
		while (i < grid->width)
		{
			ft_putnbr(grid->g[j][i].index);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
