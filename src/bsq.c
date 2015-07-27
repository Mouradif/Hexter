/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:37:59 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/27 22:47:23 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct.h"
#include "bsq.h"

char			*bsq(char *str)
{
	char	**tab;
	tab = make_grid(str);
}

t_grid			*make_grid(char *str)
{
	char 			**ret;
	unsigned int	lines;

	i = 0;
	lines = get_nb_lines(str);
	if (lines)

		ret = malloc(lines * sizeof(t_cell));
	else
		return (NULL);
	while (*str)
	{
	}
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
