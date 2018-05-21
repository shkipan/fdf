/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_colisons.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 10:10:17 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 15:20:36 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_change_color(int key, t_fdf *fdf)
{
	int i;
	int j;

	if (fdf->curr_color == 0 && key == 81)
	{
		fdf->curr_color = 11;
		return ;
	}
	if (fdf->curr_color == 11 && key == 75)
	{
		fdf->curr_color = 0;
		return ;
	}
	if (key == 75)
		fdf->curr_color += 1;
	if (key == 81)
		fdf->curr_color -= 1;
	i = -1;
	while (++i < fdf->num_y)
	{
		j = -1;
		while (++j < fdf->num_x)
			fdf->map[i][j].rgb = fdf->color[fdf->curr_color];
	}
}

void	create_colors(t_fdf *fdf)
{
	fdf->color = (int *)malloc(sizeof(int) * 16);
	fdf->color[0] = 0xFFFFFF;
	fdf->color[1] = 0xFF7603;
	fdf->color[2] = 0xFFB600;
	fdf->color[3] = 0xC9C600;
	fdf->color[4] = 0x1CA8FF;
	fdf->color[5] = 0xF909ED;
	fdf->color[6] = 0x63CCCA;
	fdf->color[7] = 0xFFFF00;
	fdf->color[8] = 0xFF0000;
	fdf->color[9] = 0x00FF00;
	fdf->color[10] = 0x0000FF;
	fdf->color[11] = 0xce7f39;
	fdf->color[12] = 0x000000;
	fdf->color[13] = 0x030868;
	fdf->color[14] = 0x3E0366;
	fdf->color[15] = 0x005618;
}

void	start_colisions(t_fdf *fdf)
{
	fdf->num_y = 0;
	create_colors(fdf);
	fdf->curr_color = 0;
	fdf->bg_curr_color = 12;
	fdf->normal = 0.0;
	fdf->angle.z = 0;
	fdf->usage = 0;
	fdf->start_point.x = WIN_X / 2;
	fdf->start_point.y = WIN_Y / 2;
	fdf->height_mode = 0;
}
