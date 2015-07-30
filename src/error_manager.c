/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 08:37:24 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 19:34:49 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "err.h"

int			ft_errno(int err)
{
	g_errno = err;
	return (0);
}

void		*v_errno(int err)
{
	g_errno = err;
	return (NULL);
}
