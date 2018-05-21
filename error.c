/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:55:05 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/12 14:08:39 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error(int code)
{
	if (code == 1)
		ft_putstr("Usage: ./fdf file_name\n");
	if (code == 2)
		ft_putstr("Can't open this file\n");
	if (code == 3)
		ft_putstr("Wrong symbols in file, only numbers and RGB\n");
	if (code == 4)
		ft_putstr("Wrong number of symbols in lines in file\n");
	if (code == 5)
		ft_putstr("Not a readable file\n");
	if (code == 6)
		ft_putstr("Wrong color description\n");
	exit(code);
}
