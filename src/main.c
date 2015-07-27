/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:36:56 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/27 17:53:05 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "bsq.h"

#define SIZE_BUF 20

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ac--;
		av++;

	}
}

int		bsq_from_stdin()
{
	char	*buf;
	size_t	i;
	size_t	len;
	size_t	count;


	buf = malloc(&buf, SIZE_BUF);
	i = 0;
	len = SIZE_BUF;
	count = read(STDIN_FILENO, buf, len - i);
	while (count > 0)
	{
		i += count;
		if (len - i == 0)
		{
			len += SIZE_BUF;
			buf = ft_realloc(buf, len);
		}
	}
}
