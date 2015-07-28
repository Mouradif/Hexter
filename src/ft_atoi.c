/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 21:12:39 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/11 22:46:21 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char *str)
{
	int	res;
	int i;
	int negative;

	res = 0;
	i = 0;
	negative = 0;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	while (*str)
	{
		res = *str - '0' + res * 10;
		str++;
	}
	if (negative)
	{
		res = 0 - res;
	}
	return (res);
}
