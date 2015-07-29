/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 08:37:24 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/29 09:01:07 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	g_errno;

int			errno(int err)
{
	g_errno = err;
	return (0);
}

void		*v_errno(int err)
{
	g_errno = err;
	return (NULL);
}
