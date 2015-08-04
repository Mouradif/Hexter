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

void	brainfuck(unsigned char *p, char *input, int i)
{
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
	unsigned char	*p;
	char			*input;
	int				i;

	input = (char*)malloc(4096);
	octets = (unsigned char*)malloc(2048);
	i = 0;
	while (i < 2048)
	{
		octets[i] = 0;
		i++;
	}
	i = 0;
	p = octets;
	if (argc == 2)
	{
		input = argv[1];
		brainfuck(p, input, i);
	}
	free(input);
	free(octets);
	return (0);
}