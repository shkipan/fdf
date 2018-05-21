/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:25:40 by dskrypny          #+#    #+#             */
/*   Updated: 2018/04/26 19:49:48 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_line(t_fdf *fdf, t_point *start, t_point *end)
{
	float		k;
	int			b;
	int			i;

	k = 1;
	if (end->x - start->x != 0)
		k = ((float)(end->y - start->y) / (float)(end->x - start->x));
	else
		k = 0;
	b = (int)end->y - k * end->x;
	i = 0;
	while (i + start->x <= end->x)
	{
		mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, start->x + i,
				(int)(k * (start->x + i) + b), 0xFFFFFF);
		i++;
	}
}
