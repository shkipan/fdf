/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 16:36:22 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:53:53 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		usage(t_fdf *fdf, int x, int y)
{
	if (x > WIN_X - 305 && y < 250 && fdf->usage)
		return (0);
	if (x > WIN_X - 305 && y < 35 && !(fdf->usage))
		return (0);
	if (x < 200 && y < 115)
		return (0);
	if (y > WIN_Y - 25)
		return (0);
	if (y < 25)
		return (0);
	if (x < 25)
		return (0);
	if (x > WIN_X - 25)
		return (0);
	return (1);
}

void	brezenham(t_fdf *fdf, t_point p1, t_point p2)
{
	float	dx;
	float	dy;
	float	x;
	float	y;
	int		length;

	dx = (p2.x - p1.x >= 0 ? 1 : -1);
	dy = (p2.y - p1.y >= 0 ? 1 : -1);
	length = ABS(p1.x - p2.x) > ABS(p1.y - p2.y) ? ABS(p1.x - p2.x) + 1 :
		ABS(p1.y - p2.y) + 1;
	if (ABS(p1.x - p2.x) > ABS(p1.y - p2.y))
		dy *= (float)ABS(p1.y - p2.y) / (float)ABS(p1.x - p2.x);
	else
		dx *= (float)ABS(p1.x - p2.x) / (float)ABS(p1.y - p2.y);
	x = (float)p1.x;
	y = (float)p1.y;
	while (length--)
	{
		if ((x < WIN_X && y < WIN_Y) && (x > 0 && y > 0) && usage(fdf, x, y))
			put_pixel_image(fdf, x, y, p1.rgb);
		x += dx;
		y += dy;
	}
}
