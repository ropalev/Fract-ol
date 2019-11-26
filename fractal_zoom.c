/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_zoom.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:17:08 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 14:18:42 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		figure_zoom_in(double scale, int x, int y, void *param)
{
	t_common	*ptr;

	ptr = (t_common *)param;
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	ptr->jul_fr.zoom *= scale;
	ptr->jul_fr.movex += (x - WW / 2) / (WW * 0.5 * ptr->jul_fr.zoom);
	ptr->jul_fr.movey += (y - WH / 2) / (WW * 0.5 * ptr->jul_fr.zoom);
	julia(ptr, &(ptr->jul_fr));
	return (0);
}

int		figure_zoom_out(double scale, int x, int y, void *param)
{
	t_common	*ptr;

	ptr = (t_common *)param;
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	ptr->jul_fr.zoom /= scale;
	ptr->jul_fr.movex -= (x - WW / 2) / (WH * 0.5 * ptr->jul_fr.zoom);
	ptr->jul_fr.movey -= (y - WH / 2) / (WH * 0.5 * ptr->jul_fr.zoom);
	julia(ptr, &(ptr->jul_fr));
	return (0);
}

int		fractal_move_x(double scale, void *param)
{
	t_common	*ptr;

	ptr = (t_common *)param;
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	ptr->jul_fr.movex += scale * ptr->jul_fr.zoom;
	julia(ptr, &(ptr->jul_fr));
	return (0);
}

int		fractal_move_y(double scale, void *param)
{
	t_common	*ptr;

	ptr = (t_common *)param;
	mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
	ptr->jul_fr.movey += scale * ptr->jul_fr.zoom;
	julia(ptr, &(ptr->jul_fr));
	return (0);
}
