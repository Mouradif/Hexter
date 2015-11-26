/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 15:54:52 by jlawson           #+#    #+#             */
/*   Updated: 2015/09/12 17:21:07 by jlawson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

int		ft_putchar(char c);
int		ft_err_putchar(char c);
int		ft_putstr(char *str);
int		ft_err_putstr(char *str);
void		ft_putnbr(int nb);
void		ft_err_putnbr(int nb);
int		ft_atoi(char *str);
int		count_digits(char *str);
int		ft_strlen(char *str);
void		ft_sort_integer_table(int *tab, int size);
unsigned int	ft_min(unsigned int *r, unsigned int size);
int		ft_strcmp(char *s1, char *s2);
void		ft_strcpy(char *s1, char *s2);

#endif
