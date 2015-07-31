/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 18:18:21 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 19:34:49 by jlawson          ###   ########.fr       */
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

	i = ft_getline(&str, grid->fd);
	if (!i)
	{
		ft_errno(1);
		free(str);
		return ;
	}
	if (EQUAL(str[i - 1], str[i - 2], str[i - 3]))
		ft_errno(2);
	if (!g_errno)
	{
		grid->plein = str[i - 1];
		grid->obs = str[i - 2];
		grid->vide = str[i - 3];
		str[i - 3] = '\0';
		if (ft_strlen(str) != count_digits(str))
			ft_errno(9);
		grid->height = ft_atoi(str);
		grid->g = malloc(sizeof(t_cell*) * grid->height);
	}
	free(str);
}
