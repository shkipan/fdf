/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 19:43:47 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 12:48:37 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	rotate_z_cv(t_fdf *fdf, int angle)
{
	float	alpha;
	int		i;
	int		j;
	int		x;
	int		y;

	alpha = angle * M_PI / 180;
	fdf->normal += alpha;
	i = 0;
	while (i < fdf->num_y)
	{
		j = 0;
		while (j < fdf->num_x)
		{
			x = fdf->map[i][j].x - fdf->start_point.x;
			y = fdf->map[i][j].y - fdf->start_point.y;
			fdf->map[i][j].x = round((float)x * cos(alpha) - (float)y *
					sin(alpha)) + fdf->start_point.x;
			fdf->map[i][j].y = round((float)x * sin(alpha) + (float)y *
					cos(alpha)) + fdf->start_point.y;
			j++;
		}
		i++;
	}
}
