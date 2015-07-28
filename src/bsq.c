/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:37:59 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/28 13:40:47 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "struct.h"
#include "bsq.h"

#define NOT_EQUAL(a, b, c) ((a != b && b != c && c != a) ? 1 : 0)

char			*bsq(char *str)
{
	char	**tab;
	tab = make_grid(str);
}

t_grid			*make_grid(char *str)
{
	char 			**ret;
	unsigned int	lines;


	taille = ft_atoi(str);
	if (taille)
		grid
}

t_grid			*init_grid(unsigned int taille, char vide, char obstacle,
		char plein)
{
	t_grid			*grid;
	unsigned int	i;

	grid = malloc(sizeof(t_grid));
	if (grid)
	{
		grid->taille = taille;
		grid->vide = vide;
		grid->plein = plein;
		grid->grid = malloc(taille * sizeof(t_cell *));
		i = 0;
		if (grid->grid)
		{
			while (i < taille)
			{
				grid->grid[i] = malloc(taille * sizeof(t_cell));
				i++;
			}
		}
	}
	return (grid);
}

unsigned int	size_line(char *str)
{
	unsigned int ret;

	ret = 0;
	while (str[ret] && str[ret] != '\n')
		ret++;
	return (ret);
}

t_grid			*get_param(char *str)
{
	unsigned int	i;
	unsigned int	size_line;
	unsigned int	taille;

	i = 0;
	size_line = size_line(str);
	if (size_line < 4 && !(*str >= '1' && *str <= '9'))
		return (NULL);
	taille = 0;
	while (i < size_line - 3 && str[i] >= '0' && str[i] <= '9')
	{
		taille = taille * 10 + str[i] - '0';
		i++;
	}
	if (i == size_line - 3 && ft_foreach((str + i), 3, &is_printable)
			&& NOT_EQUAL(str[i], str[i + 1], str[i + 2]))
		return(init_grid(taille, str[i], str[i + 1], str[i + 2]));
	else
		return (NULL);
}

int				is_printable(char c)
{
	if (c >= 33 && c <= 126)
		return (1);
	return (0);
}


unsigned int	ft_count_lines(char *str)
{
	unsigned int ret;

	ret = 0;
	while (*str)
	{
		if (*str == '\n')
			ret++;
		str++;
	}
	return (ret);
}

unsigned int	get_nb_lines(char *str)
{
	unsigned int res;

	res = 0;
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res);
}
