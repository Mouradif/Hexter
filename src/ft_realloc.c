/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:42:32 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 12:46:00 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "bsq.h"
#include "struct.h"
#include "ft.h"

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

char	*ft_realloc(char *buf, size_t size)
{
	char	*ret;
	int		len;

	if (size == 0)
		return (buf);
	else
	{
		len = ft_strlen(buf);
		ret = malloc(len + size + 1);
		ft_cpy(ret, buf, size + len + 1);
		free(buf);
	}
	return (ret);
}
