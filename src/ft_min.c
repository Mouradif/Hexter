/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/30 21:25:15 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/30 21:41:57 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_min(unsigned int *r, int size)
{
	unsigned int min;
	int i;

	i = 0;
	min = r[0];
	while (i++ < size)
		min = (r[i] < min) ? r[i] : min;
	return (min);
}