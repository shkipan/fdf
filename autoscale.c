/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autoscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:47:48 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:47:42 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	autoscale(t_fdf *fdf)
{
	float x;
	float y;
	float z;

	x = (float)(WIN_X) / 2.0 - 200;
	y = (float)(WIN_Y) / 2.0 - 400;
	z = (float)(WIN_Y) / 2.0 - 350.0;
	fdf->def_scale.x = round((float)x / ((float)fdf->num_x));
	fdf->def_scale.y = round((float)y / ((float)fdf->num_y));
	fdf->def_scale.z = 10;
	fdf->scale.x = fdf->def_scale.x;
	fdf->scale.y = fdf->def_scale.y;
	fdf->scale.z = 15;
}
