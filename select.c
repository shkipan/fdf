/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 13:05:27 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 20:21:26 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	scale_map(int key, t_fdf *fdf)
{
	if (key == 69)
		fdf->scale.z += 2;
	if (key == 78 && fdf->scale.z > 2)
		fdf->scale.z -= 2;
	if (key == 126)
		fdf->scale.y += 2;
	if (key == 125 && fdf->scale.y > 2)
		fdf->scale.y -= 2;
	if (key == 124)
		fdf->scale.x += 2;
	if (key == 123 && fdf->scale.x > 2)
		fdf->scale.x -= 2;
	if (key == 7 && fdf->scale.x < 20000 && fdf->scale.y < 20000)
	{
		fdf->scale.x += 2;
		fdf->scale.y += 2;
	}
	if (key == 6 && fdf->scale.x > 2 && fdf->scale.y > 2)
	{
		fdf->scale.x -= 2;
		fdf->scale.y -= 2;
	}
	recreate_map(fdf);
}

void	move_map(int key, t_fdf *fdf)
{
	int dx;
	int dy;

	dx = 0;
	dy = 0;
	if (key == 13 || key == 1)
		dy = (key == 13) ? -10 : 10;
	if (key == 0 || key == 2)
		dx = (key == 0) ? -10 : 10;
	fdf->start_point.x += dx;
	fdf->start_point.y += dy;
	recreate_map(fdf);
}
