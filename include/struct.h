/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 21:22:48 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/28 16:13:33 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_cell
{
	char			cell;
	unsigned int	index;
}					t_cell;

typedef struct		s_grid
{
	size_t			taille;
	char			*str;
	char			vide;
	char			obstacle;
	char			plein;
	struct s_cell	**grid;
}					t_grid;

#endif
