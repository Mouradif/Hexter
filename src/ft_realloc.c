/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:42:32 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/27 17:40:27 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

void	*ft_realloc(void *buf, size_t size)
{
	char	*ret;

	if ( size == 0)
		return (NULL);
	else
	{
		ret = malloc(size);
		ft_cpy(ret, buf);
		free(buf);
		buf = ret;
	}
	return (buf);
}

void	ft_cpy(void *dest, void *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && src[i])
	{
		res[i] = src[i];
		i++;
	}
	while (i < size)
	{
		res[i] = '\0';
		i++;
	}
}
