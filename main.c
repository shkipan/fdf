/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:18:56 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 15:09:53 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int ac, char **av)
{
	t_fdf	fdf;
	int		fd;

	if (ac != 2)
		error(1);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error(2);
	start_colisions(&fdf);
	reader(fd, &fdf);
	close(fd);
	fdf.mlx_ptr = mlx_init();
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WIN_X, WIN_Y, "window");
	hook_key(&fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}
