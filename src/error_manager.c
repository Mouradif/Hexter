/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 08:37:24 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/29 19:54:45 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			errno(int err, t_grid *grid)
{
	g_errno = err;
	ft_free(grid);
	return (0);
}

void		*v_errno(int err, t_grid *grid)
{
	g_errno = err;
	ft_free(grid);
	return (NULL);
}
