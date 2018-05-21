/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:48:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 14:22:29 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_height(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->num_y)
	{
		j = 0;
		while (j < fdf->num_x)
		{
			if (fdf->map[i][j].z)
				fdf->map[i][j].y -= 15;
			j++;
		}
		i++;
	}
}

void	dec_height(t_fdf *fdf)
{
	int		i;
	int		j;

	i = 0;
	while (i < fdf->num_y)
	{
		j = 0;
		while (j < fdf->num_x)
		{
			if (fdf->map[i][j].z)
				fdf->map[i][j].y += 15;
			j++;
		}
		i++;
	}
}
