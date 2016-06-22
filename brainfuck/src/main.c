/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/17 18:57:46 by exam              #+#    #+#             */
/*   Updated: 2015/08/01 08:03:04 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ftlib.h"

void	open_bracket(char *input, int *i)
{
	int depth;

	depth = 1;
	while (depth > 0)
	{
		*i = *i + 1;
		if (input[*i] == '[')
			depth++;
		else if (input[*i] == ']')
			depth--;
	}
}

void	close_bracket(char *input, int *i)
{
	int depth;

	depth = -1;
	while (depth < 0)
	{
		*i = *i - 1;
		if (input[*i] == '[')
			depth++;
		if (input[*i] == ']')
			depth--;
	}
}

void	brainfuck(unsigned char *p, char *input)
{
	int i;

	i = 0;
	while (input[i])
	{
		if (input[i] == '>')
			p++;
		else if (input[i] == '<')
			p--;
		else if (input[i] == '+')
			(*p)++;
		else if (input[i] == '-')
			(*p)--;
		else if (input[i] == '.')
			ft_putchar(*p);
		else if ((input[i] == '[') && *p == 0)
		{
			open_bracket(input, &i);
		}
		else if (input[i] == ']' && *p != 0)
		{
			close_bracket(input, &i);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	unsigned char	*octets;
	int				i;
	int				fd;
	char			*file;
	struct stat		file_info;

	octets = (unsigned char*)malloc(2048);
	i = 0;
	while (i < 2048)
	{
		octets[i] = 0;
		i++;
	}
	if (argc == 2 && !stat(argv[1], &file_info) &&
			(file = malloc(file_info.st_size + 1)))
	{
		fd = open(argv[1], O_RDONLY);
		read(fd, file, file_info.st_size);
		close(fd);
		brainfuck(octets, file);
	}
	free(octets);
	return (0);
}
