/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:25:28 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 14:51:51 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	write(1, "use ./fractol with one of arguments: ", 37);
	write(1, "j - Julia, b - Mandelbrot , s - Burning Ship\n", 46);
}

int     ex(void)
{
    exit(0);

}