/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/27 18:13:22 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"
#include "ft.h"

#define SIZE_BUF 20

int		main(int ac, char **av)
{
	char *str;

	if (ac > 1)
	{
		ac--;
		av++;
	}
	else
	{
		str = bsq_from_stdin();
		ft_putstr(str);
		free(str);
	}
}

char	*bsq_from_stdin()
{
	char	*buf;
	size_t	i;
	size_t	len;
	size_t	count;


	buf = malloc(SIZE_BUF);
	i = 0;
	len = SIZE_BUF;
	count = read(STDIN_FILENO, buf, len);
	while (count > 0)
	{
		i += count;
		if (len - i == 0)
		{
			len += SIZE_BUF;
			buf = ft_realloc(buf, len);
		}
		count = read(STDIN_FILENO, (buf + i), (len - i));
	}
	return (buf);
}
