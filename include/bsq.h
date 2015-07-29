/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 16:38:51 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 08:38:09 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include "struct.h"

int				bsq_from_file(int ac, char **av);
char			*read_stdin(void);
char			*ft_realloc(char *buf, size_t size);
void			ft_cpy(char *dest, char *src, size_t size);
char			**make_grid(char *str);
unsigned int	ft_count_lines(char *str);
size_t			size_line(char *str);
int				is_printable(char c);
int				ft_test_foreach(char *tab, int length, int (*f) (char));
t_grid			*get_param(char *str);
t_grid			*init_grid(size_t size, char *str, size_t pointer_char);
int				errno(int err);

#endif
