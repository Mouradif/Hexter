/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 21:25:15 by mkejji            #+#    #+#             */
/*   Updated: 2015/09/12 17:21:24 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_min(unsigned int *r, unsigned int size)
{
	unsigned int	min;
	unsigned int	i;

	i = 0;
	min = r[0];
	while (i < size)
	{
		min = (r[i] < min) ? r[i] : min;
		i++;
	}
	return (min);
}
