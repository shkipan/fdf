/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 14:48:42 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 13:08:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_z(t_fdf *fdf)
{
	fdf->scale.z += 10;
	recreate_map(fdf);
}

void	dec_z(t_fdf *fdf)
{
	if (fdf->scale.z >= 10)
	{
		fdf->scale.z -= 10;
		recreate_map(fdf);
	}
}
