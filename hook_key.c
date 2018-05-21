/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:01:20 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:51:27 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define ARROW_KEY (key == 123 || key == 124 || key == 125 || key == 126)

void	change_key(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (key == 75 || key == 81)
		ft_change_color(key, fdf);
	if (key == 15)
	{
		fdf->angle.z += 15;
		rotate_z_cv(fdf, 15);
	}
	if (key == 69 || key == 78 || key == 6 || key == 7 || ARROW_KEY)
		scale_map(key, fdf);
	if (key == 32)
		fdf->usage = (fdf->usage) ? 0 : 1;
	if (key == 13 || key == 0 || key == 1 || key == 2)
		move_map(key, fdf);
	if (key == 8)
		move_def(fdf);
	if (key == 4)
		fdf->height_mode = (fdf->height_mode) ? 0 : 1;
	if (key == 11)
		fdf->bg_curr_color = (fdf->bg_curr_color == 15) ? 12 :
			fdf->bg_curr_color + 1;
}

int		take_key(int key, t_fdf *fdf)
{
	fdf->angle.z -= (fdf->angle.z == 360) ? 360 : 0;
	change_key(key, fdf);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_X, WIN_Y);
	change_bg(fdf);
	height_mode(fdf);
	fill_image(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	info_print(fdf);
	return (0);
}

void	hook_key(t_fdf *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_X, WIN_Y);
	fill_image(fdf);
	mlx_hook(fdf->win_ptr, 2, 5, take_key, fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	info_print(fdf);
}
