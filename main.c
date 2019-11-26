/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:58:21 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 14:43:38 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		keyboard_action(int keycode, void *param)
{
	if (keycode == 123)
		fractal_move_x(0.10, param);
	if (keycode == 124)
		fractal_move_x(-0.10, param);
	if (keycode == 125)
		fractal_move_y(-0.10, param);
	if (keycode == 126)
		fractal_move_y(0.10, param);
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		fractal_start(param);
	return (0);
}

int		mouse_action(int button, int x, int y, void *param)
{
	if (button == 4)
		figure_zoom_in(1.5, x, y, param);
	if (button == 5)
		figure_zoom_out(1.5, x, y, param);
	return (0);
}

int		main(int argc, char **argv)
{
	t_common	ptr;

	if (argc == 2 && (argv[1][0] == 's' || (argv[1][0] == 'j') ||
				argv[1][0] == 'b') && (argv[1][1] == '\0'))
	{
		ptr.num = argv[1][0];
		ptr.mlx_ptr = mlx_init();
		ptr.win_ptr = mlx_new_window(ptr.mlx_ptr, WW, WH, "Window");
		ptr.img_ptr = mlx_new_image(ptr.mlx_ptr, WW, WH);
		ptr.image = mlx_get_data_addr(ptr.img_ptr,
				&(ptr.bits_per_pixel), &(ptr.size_line), &ptr.endian);
		fractal_start(&ptr);
		mlx_hook(ptr.win_ptr, 2, 2, &keyboard_action, (void *)&ptr);
		mlx_hook(ptr.win_ptr, 4, 4, &mouse_action, (void *)&ptr);
		mlx_hook(ptr.win_ptr, 6, 6, &mouse_move, (void *)&ptr);
        mlx_hook(ptr.win_ptr, 17, 17, &ex, (void *)&ptr);
		mlx_loop(ptr.mlx_ptr);
	}
	else
	{
		usage();
		exit(0);
	}
}
