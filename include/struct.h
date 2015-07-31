/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 21:22:48 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/31 04:11:03 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include <stdlib.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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
	char			color[8];
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
