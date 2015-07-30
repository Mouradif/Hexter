/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 18:18:21 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 12:58:47 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"
#include "ft.h"
#include "struct.h"
#include "err.h"
#define EQUAL(a,b,c) (a == b || b == c || a == c)

void	ft_set_params(t_grid *grid)
{
	char				str[14];
	char				c;
	unsigned int		ret;
	size_t				i;

	i = 0;
	while ((ret = read(grid->fd, (str + i), 1)) && str[i] != '\n')
	{
		if (str[i] == '\0')
		{
			errno(11);
			break;
		}
		i++;
	}
	c = 0;
	read(grid->fd, &c, 1);
	if (EQUAL(str[i], str[i - 1], str[i - 2]))
		errno(2);
	if (!g_errno)
	{
		grid->plein = str[i];
		str[i] = '\0';
		grid->obs = str[i - 1];
		str[i - 1] = '\0';
		grid->vide = str[i - 2];
		str[i - 2] = '\0';
		if (ft_strlen(str) != count_digits(str))
			errno(9);
		grid->height = ft_atoi(str);
		grid->grid = malloc(sizeof(t_cell*) * grid->height);
	}
}
