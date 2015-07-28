/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:38:51 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/28 16:33:29 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

int				bsq_from_file(int ac, char **av);
char			*read_stdin(void);
char			*ft_realloc(char *buf, size_t size);
void			ft_cpy(char *dest, char *src, size_t size);
char			**make_grid(char *str);
unsigned int	ft_count_lines(char *str);
size_t			size_line(char *str);
int				is_printable(char c);
void			ft_foreach(char *tab, int length, void (*f) (char));

t_grid			*get_param(char *str);
t_grid			*init_grid(unsigned int taille, char vide, char obstacle,
		char plein);

#endif
