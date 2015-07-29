/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/15 15:54:52 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 22:37:52 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_err_putchar(char c);
void	ft_putstr(char *str);
void	ft_err_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_err_putnbr(int nb);
int		ft_atoi(char *str);
int		count_digits(char *str);
int		ft_strlen(char *str);
void	ft_sort_integer_table(int *tab, int size);

#endif
