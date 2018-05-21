# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dskrypny <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 19:28:18 by dskrypny          #+#    #+#              #
#    Updated: 2018/05/19 15:11:11 by dskrypny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = fdf

FILES = autoscale.c \
		brezenham.c \
		error.c \
		fill_img.c \
		freesher.c \
		ft_check_num.c \
		height_mode.c \
		hook_key.c \
		info_print.c \
		main.c \
		map.c \
		move_def.c \
		reader.c \
		rotate.c \
		scale.c \
		select.c \
		start_colisons.c \

all: $(NAME)

$(NAME):
	make -C libft/
	gcc $(FLAGS) -lmlX $(FILES) -framework OpenGL -framework Appkit libft/libft.a -o $(NAME)

clean:
	make clean -C libft/

fclean:
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all

mlx:
	man /usr/share/man/man3/mlx.1

loop:
	man /usr/share/man/man3/mlx_loop.1

image:
	man /usr/share/man/man3/mlx_new_image.1

window:
	man /usr/share/man/man3/mlx_new_window.1

pixel:
	man /usr/share/man/man3/mlx_pixel_put.1

