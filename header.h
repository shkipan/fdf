/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 19:26:47 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:08:02 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft/libft.h"
# include "libft/mlx.h"
# include <fcntl.h>
# include <math.h>

# define WIN_X 1200
# define WIN_Y 1200

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
	int		zero;
	int		rgb;
}				t_point;

typedef struct	s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		num_x;
	int		num_y;
	int		info_y;
	t_point	scale;
	t_point	def_scale;
	t_point	angle;
	float	normal;
	t_point	start_point;
	char	*data;
	t_point	**map;
	int		curr_color;
	int		bg_curr_color;
	int		*color;
	int		usage;
	int		height_mode;
}				t_fdf;

void			start_colisions(t_fdf *fdf);
void			autoscale(t_fdf *fdf);
void			set_scale(t_fdf *fdf);
void			ft_change_color(int key, t_fdf *fdf);
void			hook_key(t_fdf *fdf);
void			reader(int fd, t_fdf *fdf);
int				ft_check_num(char *str);
void			fill_image(t_fdf *fdf);
void			change_bg(t_fdf *fdf);
void			height_mode(t_fdf *fdf);

void			create_map(t_fdf *fdf);
void			recreate_map(t_fdf *fdf);

void			scale_map(int key, t_fdf *fdf);
void			move_map(int key, t_fdf *fdf);

void			move_def(t_fdf *fdf);

void			brezenham(t_fdf *fdf, t_point p1, t_point p2);
void			rotate_z_cv(t_fdf *fdf, int angle);
void			put_pixel_image(t_fdf *fdf, int x, int y, int color);

void			freesher(char **ptr);
void			error(int code);
void			info_print(t_fdf *fdf);

#endif
