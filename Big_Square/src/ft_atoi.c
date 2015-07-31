/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 02:49:59 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/29 22:09:24 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_digits(char *str)
{
	int i;

	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (i);
}

int	ft_power(int i, int exp)
{
	return ((exp == 0) ? 1 : i * ft_power(i, exp - 1));
}

int	ft_atoi(char *str)
{
	int i;
	int digits;
	int result;

	result = 0;
	i = -1;
	digits = count_digits(str);
	while (++i < digits)
		result += (str[i] - 48) * ft_power(10, digits - i - 1);
	return (result);
}
