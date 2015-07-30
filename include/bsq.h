/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:38:51 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/30 13:36:03 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include "struct.h"

int		ft_allowed_chars(t_grid *grid, char c);
void	read_file(char *path);
void	ft_read(t_grid *grid);
void	ft_cell_increment(t_grid *grid, size_t i, size_t j);
void	ft_remap(t_grid *grid);
int		ft_cell_search(t_grid *grid, size_t i, size_t j);
void	ft_set_params(t_grid *grid);
char	*ft_realloc(char *buf, size_t size);
int		is_printable(char c);
t_grid	*init_grid(int fd);
void	print_grid(t_grid *grid);
void	read_first_line(t_grid *grid);
char	*ft_getline(int fd);

#endif
