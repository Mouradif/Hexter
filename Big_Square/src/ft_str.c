/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkejji <mkejji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/31 05:08:18 by mkejji            #+#    #+#             */
/*   Updated: 2015/07/31 06:35:50 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		abs(int i)
{
	return ((i < 0) ? -i : i);
}

int		ft_charcmp(char c1, char c2)
{
	int i;

	i = 0;
	if (c1 != c2)
		return (abs(c1 - c2));
	i++;
	return (abs(c1 - c2));
}

void	ft_strcpy(char *s1, char *s2)
{
	int i;
	char c;

	i = 0;
	while (ft_charcmp(s2[i], 0))
	{
		c = ft_charcmp(s2[i], 0);
		s1[i] = c;
		i++;
	}
}
