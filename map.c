/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_points.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:48:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:47:18 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	center(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	step;

	step.y = ABS(fdf->map[0][0].y -
			fdf->map[fdf->num_y - 1][fdf->num_x - 1].y) / 2 +
		fdf->map[0][0].y - fdf->start_point.y;
	step.x = ABS(fdf->map[fdf->num_y - 1][0].x -
			fdf->map[0][fdf->num_x - 1].x) / 2 +
		fdf->map[fdf->num_y - 1][0].x - fdf->start_point.x;
	i = -1;
	while (++i < fdf->num_y)
	{
		j = -1;
		while (++j < fdf->num_x)
		{
			fdf->map[i][j].y -= step.y;
			fdf->map[i][j].x -= step.x;
		}
	}
}

void	filling(t_fdf *fdf, int i, int j, char *temp)
{
	fdf->map[i][j].x = fdf->start_point.x + j * fdf->scale.x -
		i * round((float)fdf->scale.y / tan(M_PI / 6));
	fdf->map[i][j].y = fdf->start_point.y + i * fdf->scale.y +
		j * round((float)fdf->scale.x / tan(M_PI / 3));
	fdf->map[i][j].rgb = (ft_strchr(temp, ',') != NULL) ?
		ft_atoi_hex(ft_strchr(temp, ',') + 1) :
		fdf->color[fdf->curr_color];
	if (fdf->map[i][j].rgb == -1)
		error(6);
	fdf->map[i][j].z = ft_atoi(temp);
	fdf->map[i][j].zero = (fdf->map[i][j].z == 0) ? 0 : 1;
	fdf->map[i][j].y -= fdf->map[i][j].z * fdf->scale.z;
}

void	create_map(t_fdf *fdf)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = -1;
	k = 0;
	autoscale(fdf);
	temp = ft_strsplit(fdf->data, ' ');
	fdf->map = (t_point **)malloc(sizeof(t_point *) * (fdf->num_y + 1));
	while (++i < fdf->num_y)
	{
		fdf->map[i] = (t_point *)malloc(sizeof(t_point) * (fdf->num_x + 1));
		j = -1;
		while (++j < fdf->num_x)
		{
			filling(fdf, i, j, temp[k]);
			k++;
		}
	}
	center(fdf);
	rotate_z_cv(fdf, fdf->angle.z);
	freesher(temp);
}

void	recreate_map(t_fdf *fdf)
{
	int		i;
	int		j;
	int		k;
	char	**temp;

	i = -1;
	k = 0;
	temp = ft_strsplit(fdf->data, ' ');
	while (++i < fdf->num_y)
	{
		j = -1;
		while (++j < fdf->num_x)
		{
			filling(fdf, i, j, temp[k]);
			k++;
		}
	}
	center(fdf);
	rotate_z_cv(fdf, fdf->angle.z);
	freesher(temp);
}
