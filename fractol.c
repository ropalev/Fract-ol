/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:19:20 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 14:22:57 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia(t_common *ptr, t_julia *julia)
{
	julia->y = 0;
	while (julia->y < WH)
	{
		julia->x = 0;
		while (julia->x < WW)
		{
			fractol_choose(julia, ptr->num);
			fractol_iter(julia, ptr->num);
			fractal_color(ptr, julia);
			julia->x++;
		}
		julia->y++;
	}
	mlx_put_image_to_window(ptr->mlx_ptr, ptr->win_ptr, ptr->img_ptr, 0, 0);
}

void	fractol_iter(t_julia *fractol, char num)
{
	fractol->it = 0;
	while (fractol->it < fractol->maxiterations)
	{
		if (num == 's')
		{
			fractol->oldre = fabs(fractol->newre);
			fractol->oldim = fabs(fractol->newim);
		}
		else
		{
			fractol->oldre = fractol->newre;
			fractol->oldim = fractol->newim;
		}
		fractol->newre = fractol->oldre * fractol->oldre -
			fractol->oldim * fractol->oldim + fractol->cre;
		fractol->newim = 2 * fractol->oldre * fractol->oldim + fractol->cim;
		if ((fractol->newre * fractol->newre +
					fractol->newim * fractol->newim) > 4)
			break ;
		fractol->it++;
	}
}

void	fractal_color(t_common *ptr, t_julia *fractol)
{
	if (fractol->it == fractol->maxiterations)
		fractol->color = mlx_get_color_value(ptr->mlx_ptr, 0x000000);
	else
		fractol->color = ((((fractol->red + fractol->it) % 256) << 16) |
				(((fractol->green + fractol->it) % 256) << 8) |
				(((fractol->blue + fractol->it) % 256)));
	fractol->idx = fractol->x * (ptr->bits_per_pixel) /
		8 + fractol->y * (ptr->size_line);
	ptr->image[fractol->idx] = fractol->color & 0xFF;
	ptr->image[fractol->idx + 1] = (fractol->color & 0xFF00) >> 8;
	ptr->image[fractol->idx + 2] = (fractol->color & 0xFF0000) >> 16;
}

void	fractol_choose(t_julia *fractol, char num)
{
	if (num == 'j')
	{
		fractol->newre = 1.5 * (fractol->x - WW / 2) /
			(0.5 * fractol->zoom * WW) + fractol->movex;
		fractol->newim = (fractol->y - WH / 2) /
			(0.5 * fractol->zoom * WH) + fractol->movey;
	}
	if (num == 'b' || num == 's')
	{
		fractol->cre = 1.5 * (fractol->x - WW / 2) /
			(0.5 * fractol->zoom * WW) + fractol->movex;
		fractol->cim = (fractol->y - WH / 2) /
			(0.35 * fractol->zoom * WH) + fractol->movey;
		fractol->newre = 0;
		fractol->newim = 0;
	}
}
