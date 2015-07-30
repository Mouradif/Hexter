/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 18:18:21 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 14:13:03 by jlawson          ###   ########.fr       */
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
	char				*str;
	size_t				i;

	i = 0;
	str = ft_getline(grid->fd);
	i = ft_strlen(str) - 1;
	if (EQUAL(str[i - 1], str[i - 2], str[i - 3]))
		errno(2);
	if (!g_errno)
	{
		grid->plein = str[i - 1];
		grid->obs = str[i - 2];
		grid->vide = str[i - 3];
		str[i - 3] = '\0';
		if (ft_strlen(str) != count_digits(str))
			errno(9);
		grid->height = ft_atoi(str);
		grid->grid = malloc(sizeof(t_cell*) * grid->height);
	}
}
