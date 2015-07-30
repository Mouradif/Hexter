/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 12:59:20 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 23:04:31 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "err.h"
#include "ft.h"
#include "bsq.h"

#define BUFFER_SIZE 100

void	ft_memset(char *buf, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		buf[i] = '\0';
		i++;
	}
}

int		ft_getline(char **buf, int fd)
{
	size_t		count;
	size_t		size;
	size_t		i;

	size = BUFFER_SIZE;
	*buf = malloc(sizeof(char) * size + 1);
	i = 0;
	if (*buf)
	{
		ft_memset(*buf, size + 1);
		while (count = read(fd, (*buf + i), 1) && (*buf)[i]
				&& (*buf)[i] != '\n')
		{
			i += count;
			if (i == size)
			{
				size += BUFFER_SIZE;
				*buf = ft_realloc(*buf, size + 1);
			}
		}
		if (i > 0 && (*buf)[i] != '\n')
			return (ft_errno(6));
		(*buf)[i] = 0;
	}
	return (i);
}
