/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:50:20 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 09:52:50 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	put_pixel_image(t_fdf *fdf, int x, int y, int color)
{
	int				bpp;
	int				sl;
	int				e;
	char			*res;
	unsigned int	rgb;

	res = mlx_get_data_addr(fdf->img_ptr, &bpp, &sl, &e);
	rgb = mlx_get_color_value(fdf->mlx_ptr, color);
	ft_memcpy((void *)(res + y * sl + x * bpp / 8), (void *)&rgb, 4);
}

void	change_bg(t_fdf *fdf)
{
	int i;
	int j;

	i = -1;
	while (++i < WIN_Y)
	{
		j = -1;
		while (++j < WIN_Y)
			put_pixel_image(fdf, i, j, fdf->color[fdf->bg_curr_color]);
	}
}

void	fill_image(t_fdf *fdf)
{
	int i;
	int j;

	i = 0;
	while (i < fdf->num_y)
	{
		j = 0;
		while (j < fdf->num_x)
		{
			if (j + 1 < fdf->num_x)
				brezenham(fdf, fdf->map[i][j], fdf->map[i][j + 1]);
			if (i + 1 < fdf->num_y)
				brezenham(fdf, fdf->map[i][j], fdf->map[i + 1][j]);
			j++;
		}
		i++;
	}
}
