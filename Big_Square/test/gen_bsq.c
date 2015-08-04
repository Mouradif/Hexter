/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_bsq.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 11:31:47 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 11:45:59 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putnbr(int nb)
{

	if (nb < 0)
	{
		ft_putchar('-');
		nb = - nb;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void ft_putstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	write(STDOUT_FILENO, str, i);
}

unsigned int ft_atoi(char *str)
{
	unsigned int ret;

	ret = 0;
	while (*str)
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret);
}

void make_grid(char vide, char obs, char plein, int x, int y, int density)
{
	int i;
	int j;

	srand(time(NULL));
	ft_putnbr(y);
	ft_putchar(vide);
	ft_putchar(obs);
	ft_putchar(plein);
	ft_putchar('\n');
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			if ((rand() % y) * 2 < density)
				ft_putchar(obs);
			else
				ft_putchar(vide);
		}
		ft_putchar('\n');
	}
}

int main(int ac, char **av)
{
	int x;
	int y;
	int density;

	if (ac == 7)
	{
		x = ft_atoi(av[4]);
		y = ft_atoi(av[5]);
		density = ft_atoi(av[6]);
		make_grid(av[1][0], av[2][0], av[3][0], x, y, density);
	}
	return (0);
}
