/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:42:32 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/27 18:19:38 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"

char	*ft_realloc(char *buf, size_t size)
{
	char	*ret;

	if (size == 0)
		return (NULL);
	else
	{
		ret = malloc(size);
		ft_cpy(ret, buf, size);
		free(buf);
		buf = ret;
	}
	return (buf);
}

void	ft_cpy(char *dest, char *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dest[i] = '\0';
		i++;
	}
}
