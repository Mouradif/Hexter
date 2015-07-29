/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allowed_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 20:09:34 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 22:42:49 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "err.h"

int	ft_allowed_chars(t_grid *grid, char c)
{
	if (c == grid->obs || c == grid->vide || c == '\n')
		return (1);
	else
		return (errno(5));
}
