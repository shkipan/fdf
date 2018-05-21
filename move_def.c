/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 19:41:39 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:52:51 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_def(t_fdf *fdf)
{
	fdf->start_point.x = WIN_X / 2;
	fdf->start_point.y = WIN_Y / 2;
	autoscale(fdf);
	fdf->angle.z = 0;
	recreate_map(fdf);
}
