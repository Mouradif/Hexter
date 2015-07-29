/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 18:37:59 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 03:24:14 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"
#include "struct.h"
#include "bsq.h"

#define NOT_EQUAL(a, b, c) (a != b && b != c && c != a)

char			*bsq(char *str)
{
	char	**tab;
	tab = make_grid(str);
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
