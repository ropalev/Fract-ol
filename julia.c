/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:28:56 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 15:30:11 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	julia_init(t_julia *julia)
{
	julia->color = 0;
	julia->red = 50;
	julia->green = 100;
	julia->blue = 150;
	julia->it = 0;
	julia->y = 0;
	julia->x = 0;
	julia->idx = 0;
	julia->cre = -0.7;
	julia->cim = 0.27015;
	julia->maxiterations = MAX_ITER;
	julia->movex = 0;
	julia->movey = 0;
	julia->zoom = 1;
}

void	mandelbrot_init(t_julia *julia)
{
	julia->color = 0;
	julia->red = 150;
	julia->green = 10;
	julia->blue = 50;
	julia->it = 0;
	julia->y = 0;
	julia->x = 0;
	julia->idx = 0;
	julia->cre = -0.7;
	julia->cim = 0.27015;
	julia->maxiterations = MAX_ITER;
	julia->movex = -0.7;
	julia->movey = 0;
	julia->zoom = 1;
}

void	fractal_start(void *param)
{
	t_common	*ptr;

	ptr = (t_common *)param;
	if (ptr->num == 'j')
	{
		julia_init(&(ptr->jul_fr));
		julia(ptr, &(ptr->jul_fr));
	}
	if (ptr->num == 'b' || ptr->num == 's')
	{
		mandelbrot_init(&(ptr->jul_fr));
		julia(ptr, &(ptr->jul_fr));
	}
}
