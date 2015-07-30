/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allowed_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 20:09:34 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 17:04:35 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "err.h"

int	ft_allowed_chars(t_grid *grid, char c)
{
	if (c == grid->obs || c == grid->vide)
		return (1);
	else
		return (errno(5));
}

int	valid_line(t_grid *grid, char *str)
{
	while (*str)
	{
		if (*str != grid->vide && *str != grid->obs)
			return (0);
		str++;
	}
	return (1);
}
