/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 19:04:35 by dskrypny          #+#    #+#             */
/*   Updated: 2018/05/19 16:47:35 by dskrypny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_str(t_fdf *fdf, char *str)
{
	char *temp;

	if (fdf->data == NULL)
		fdf->data = ft_strdup(str);
	else
	{
		temp = fdf->data;
		fdf->data = ft_strjoin(fdf->data, " ");
		free(temp);
		temp = fdf->data;
		fdf->data = ft_strjoin(fdf->data, str);
		free(temp);
	}
}

void	reader(int fd, t_fdf *fdf)
{
	char	*buf;
	char	**temp;
	int		i;
	int		temp_x;
	int		c;

	temp_x = 0;
	while ((c = get_next_line(fd, &buf)) > 0)
	{
		add_str(fdf, buf);
		temp = ft_strsplit(buf, ' ');
		i = -1;
		while (temp[++i])
			ft_check_num(temp[i]);
		if (fdf->num_y == 0)
			temp_x = i;
		if (i != temp_x)
			error(4);
		freesher(temp);
		free(buf);
		fdf->num_y += 1;
	}
	(c == -1) ? error(5) : NULL;
	fdf->num_x = temp_x;
	create_map(fdf);
}
