/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:19:15 by masmit            #+#    #+#             */
/*   Updated: 2025/03/26 16:30:01 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	init_fractal_bools(t_fractal *f)
{
	f->type.mandelbrot = false;
	f->type.burning_ship = false;
	f->type.julia = false;
}

void	init_flag_bools(t_fractal *f)
{
	f->flag.invert = false;
	f->flag.maximize = false;
	f->flag.monochrome = false;
}

void	reset_julia_vars(t_fractal *f)
{
	f->zoom = 1.0;
	f->x = 0;
	f->y = 0;
	f->color = BLACK;
	f->julia.c_real = 0.7;
	f->julia.c_imag = 0.27;
}

int	valid_mouse_pos(int mouse_x, int mouse_y, t_fractal *f)
{
	if (mouse_x > f->w_size.width || mouse_x < 0)
		return (1);
	if (mouse_y > f->w_size.height || mouse_y < 0)
		return (1);
	return (0);
}
