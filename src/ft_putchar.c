/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/09 22:30:20 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 05:52:45 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

void ft_err_putchar(char c)
{
	write(STDERR_FILENO, &c, 1);
}
