/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 21:22:48 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 21:58:45 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdlib.h>

typedef struct		s_point
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	max;
}					t_point;

typedef struct		s_cell
{
	char			cell;
	unsigned int	index;
	unsigned int	sum;
}					t_cell;

typedef struct		s_grid
{
	size_t			width;
	size_t			height;
	char			vide;
	char			obs;
	char			plein;
	int				fd;
	struct s_cell	**g;
}					t_grid;

#endif
