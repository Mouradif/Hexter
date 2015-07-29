/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 19:53:21 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"
#include "ft.h"

#define BUF_SIZE (1024 * 300)

int		g_errno = 0;

char	*ft_read(int fd)
{
	char	*buf;
	size_t	i;
	size_t	len;
	size_t	count;

	buf = malloc(BUF_SIZE + 1);
	if (!buf)
		return (v_errno(6));
	i = 0;
	len = BUF_SIZE;
	while ((count = read(fd, buf, len)))
	{
		i += count;
		len += BUF_SIZE;
		buf = ft_realloc(buf, len + 1);
	}
	buf[len + 1] = '\0';
	return (buf);
}

char	*read_file(char *path)
{
	char	*buf;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (v_errno(7));
	buf = ft_read(fd);
	if (close(fd) == -1)
		return (v_errno(8));
	return (buf);
}

int		main(int ac, char **av)
{
	char	*str;
	int		i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			str = read_file(av[i]);
			ft_putstr(str);
			free(str);
		}
	}
	else
	{
		str = ft_read(STDIN_FILENO);
		ft_putstr(str);
		free(str);
	}
	return (0);
}
