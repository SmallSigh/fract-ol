/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:08 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 16:42:34 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

int	julia_iter(double zx, double zy, t_fractal *f)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (zx * zx + zy * zy > 4.0)
			break ;
		temp = zx * zx - zy * zy + f->julia.c_real;
		zy = 2.0 * zx * zy + f->julia.c_imag;
		zx = temp;
		iter++;
	}
	return (iter);
}

void	draw_julia(t_fractal *f)
{
	int		x;
	int		y;
	double	zx;
	double	zy;

	y = 0;
	while (y < f->w_size.height)
	{
		x = 0;
		while (x < f->w_size.width)
		{
			zx = (x - f->w_size.width / 2.0)
				/ (0.5 * f->zoom * f->w_size.width) + f->x;
			zy = (y - f->w_size.height / 2.0)
				/ (0.5 * f->zoom * f->w_size.height) + f->y;
			mlx_put_pixel(f->img, x, y,
				fractal_color(julia_iter(zx, zy, f), f));
			x++;
		}
		y++;
	}
}
