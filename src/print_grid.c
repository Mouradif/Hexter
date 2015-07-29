/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 21:55:50 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/29 22:33:38 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft.h"

void	print_grid(t_grid *grid)
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
	j = -1;
	while (++j < grid->height)
	{
		i = -1;
		while (++i < grid->width)
			ft_putchar(grid->grid[j][i].cell);
		ft_putchar('\n');
	}
}