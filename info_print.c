/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:00:07 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:53:52 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_usage(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 30,
			fdf->color[fdf->curr_color], "NUM / or = change color");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 50,
			fdf->color[fdf->curr_color], "NUM + or - scale height");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 70,
			fdf->color[fdf->curr_color], "arrows - scale image");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 90,
			fdf->color[fdf->curr_color], "WASD - move image");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 110,
			fdf->color[fdf->curr_color], "C - default view");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 130,
			fdf->color[fdf->curr_color], "H - switch height mode");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 150,
			fdf->color[fdf->curr_color], "B - change background");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 170,
			fdf->color[fdf->curr_color], "R - rotate figure");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 190,
			fdf->color[fdf->curr_color], "X - zoom in");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 210,
			fdf->color[fdf->curr_color], "Z - zoom out");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 230,
			fdf->color[fdf->curr_color], "Ecs - close this window");
}

void	print_more(t_fdf *fdf)
{
	char	*s;

	s = (!(fdf->height_mode)) ? "off" : "on";
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 90,
			fdf->color[fdf->curr_color], s);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 90,
			fdf->color[fdf->curr_color], "Height mode");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X / 2 - 100, WIN_Y - 25,
			fdf->color[fdf->curr_color], "Fdf by dskrypny");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 30,
			fdf->color[fdf->curr_color], "Current bg_color");
	s = ft_itoa(fdf->bg_curr_color - 12);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 180, 30,
			fdf->color[fdf->curr_color], s);
	free(s);
}

void	print_scales(t_fdf *fdf)
{
	char *s;

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, WIN_Y - 110,
			fdf->color[fdf->curr_color], "Scale x");
	s = ft_itoa(fdf->scale.x);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, WIN_Y - 110,
			fdf->color[fdf->curr_color], s);
	free(s);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, WIN_Y - 90,
			fdf->color[fdf->curr_color], "Scale y");
	s = ft_itoa(fdf->scale.y);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, WIN_Y - 90,
			fdf->color[fdf->curr_color], s);
	free(s);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, WIN_Y - 70,
			fdf->color[fdf->curr_color], "Scale z");
	s = ft_itoa(fdf->scale.z);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, WIN_Y - 70,
			fdf->color[fdf->curr_color], s);
	free(s);
}

void	info_print(t_fdf *fdf)
{
	char	*s;

	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 10,
			fdf->color[fdf->curr_color], "Current color");
	s = ft_itoa(fdf->curr_color);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, 10,
			fdf->color[fdf->curr_color], s);
	free(s);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, WIN_X - 300, 10,
			fdf->color[fdf->curr_color], "U - hide/show usage");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, WIN_Y - 50,
			fdf->color[fdf->curr_color], "Angle z");
	s = ft_itoa(fdf->angle.z);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 150, WIN_Y - 50,
			fdf->color[fdf->curr_color], s);
	free(s);
	print_more(fdf);
	print_scales(fdf);
	if (fdf->usage)
		print_usage(fdf);
}
