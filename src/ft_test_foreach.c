/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 13:28:02 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/28 13:48:59 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_test_foreach(char *str, int length, int (*f)(char))
{
	int res;
	int	i;

	res = 1;
	i = 0;
	while (res && i < length)
	{
		if (!f(str[i]))
			res = 0;
		i++;
	}
	return (res);
}
