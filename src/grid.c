/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 15:27:00 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/28 18:01:49 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_grid		*get_grid(char *str)
{
	t_grid *grid;

	grid = get_param(str);
	free(str);
	return (grid);
}

int			fill_grid(t_grid *grid)
{
	char *str;
	size_t i;
	size_t j;

	str = get_first_line(grid->str);
	j = 0;
	while (j < grid->size)
	{
		i = 0;
		while (*str && *str != '\n' && i < grid->size)
		{
			grid->grid[j][i] = *str;
			str++;
			i++;
		}
		if (i < grid->size)
			return (1);
	}
	return (0);
}

char		*get_first_line(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (0);
	return (str + i + 1);
}
