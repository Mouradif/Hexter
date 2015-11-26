/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlawson <jlawson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/11 17:55:40 by jlawson           #+#    #+#             */
/*   Updated: 2015/07/29 05:56:48 by mkejji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

int	ft_putstr(char *str)
{
	return (write(STDOUT_FILENO, str, ft_strlen(str)));
}

int	ft_err_putstr(char *str)
{
	return (write(STDERR_FILENO, str, ft_strlen(str)));
}
