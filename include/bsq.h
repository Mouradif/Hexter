/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:38:51 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 22:21:03 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include "struct.h"

int		ft_allowed_chars(t_grid *grid, char c);
char	*read_file(char *path);
char	*ft_read(t_grid *grid);
void	ft_cell_increment(t_grid *grid, size_t i, size_t j);
void	ft_remap(t_grid *grid);
int		ft_cell_search(t_grid *grid, size_t i, size_t j);
void	ft_set_params(t_grid *grid);
char	*ft_realloc(char *buf, size_t size);
int		is_printable(char c);
int		errno(int err);
void	*v_errno(int err);
void	
void	print_grid(t_grid *grid);

#endif
