/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 14:58:00 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 12:18:55 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_height(t_fdf *fdf, int i, int j)
{
	if (fdf->map[i][j].z > 0)
		return (fdf->color[4]);
	if (fdf->map[i][j].z < 0)
		return (fdf->color[9]);
	return (fdf->color[1]);
}

void	height_mode(t_fdf *fdf)
{
	int i;
	int j;
	int color;

	i = -1;
	while (++i < fdf->num_y)
	{
		j = -1;
		while (++j < fdf->num_x)
		{
			color = check_height(fdf, i, j);
			fdf->map[i][j].rgb = (!(fdf->height_mode)) ?
				fdf->color[fdf->curr_color] : color;
		}
	}
}
