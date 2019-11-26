/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvania <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 14:27:32 by lvania            #+#    #+#             */
/*   Updated: 2019/11/24 14:31:12 by lvania           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_FRACTOL_H
# define FRACTOL_FRACTOL_H

# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>

# define WW			750
# define WH			750
# define MAX_ITER	200

typedef struct	s_julia
{
	int			color;
	int			it;
	int			y;
	int			x;
	int			idx;
	int			red;
	int			green;
	int			blue;
	double		cre;
	double		cim;
	double		newre;
	double		newim;
	double		oldre;
	double		oldim;
	double		zoom;
	double		movex;
	double		movey;
	int			maxiterations;
}				t_julia;

typedef struct	s_common
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*image;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		num;
	t_julia		jul_fr;
}				t_common;

void			julia(t_common *ptr, t_julia *julia);
void			julia_init(t_julia *julia);
int				figure_zoom_out(double scale, int x, int y, void *param);
int				figure_zoom_in(double scale, int x, int y, void *param);
int				fractal_move_x(double scale, void *param);
int				fractal_move_y(double scale, void *param);
int				mouse_move(int x, int y, void *param);
void			fractal_color(t_common *ptr, t_julia *fractol);
void			fractol_iter(t_julia *fractol, char num);
void			fractal_start(void *param);
void			fractol_choose(t_julia *fractol, char num);
void			mandelbrot_init(t_julia *julia);
void			usage(void);
int             ex(void);
#endif
