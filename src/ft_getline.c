/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 12:59:20 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 16:51:30 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
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
	if (*buf)
	{
		ft_memset(*buf, size + 1);
		i = 0;
		count = read(fd, (*buf + i), 1);
		while (count > 0 && (*buf)[i] && (*buf)[i] != '\n')
		{
			i += count;
			if (i == size)
			{
				size += BUFFER_SIZE;
				*buf = ft_realloc(*buf, size + 1);
			}
			count = read(fd, (*buf + i), 1);
		}
		(*buf)[i] = 0;
	}
	return (i);
}
