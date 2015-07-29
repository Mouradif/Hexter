/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 08:37:13 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bsq.h"
#include "ft.h"

#define SIZE_BUF (1024 * 300)

int		g_errno;

char	*read_stdin(void)
{
	char	*buf;
	size_t	i;
	size_t	len;
	size_t	count;

	buf = malloc(SIZE_BUF + 1);
	i = 0;
	len = SIZE_BUF;
	while ((count = read(STDIN_FILENO, buf, len)))
	{
		i += count;
		len += SIZE_BUF;
		buf = ft_realloc(buf, len + 1);
	}
	buf[len + 1] = '\0';
	return (buf);
}

char	*read_file(char *path)
{
	char	*buf;
	size_t	i;
	size_t	len;
	size_t	count;
	int		fd;

	buf = malloc(SIZE_BUF + 1);
	i = 0;
	len = SIZE_BUF;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (errno(7));
	while ((count = read(fd, buf, len)))
	{
		i += count;
		len += SIZE_BUF;
		buf = ft_realloc(buf, len + 1);
	}
	buf[len + 1] = '\0';
	if (close(fd) == -1)
		return (errno(8));
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
		str = read_stdin();
		ft_putstr(str);
		free(str);
	}
	return (0);
}
