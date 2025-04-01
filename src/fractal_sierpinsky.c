/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sierpinsky.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:08 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 15:13:56 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

uint32_t	get_mono_colors_julia(int intensity)
{
	return (SET_MONO((uint8_t)intensity));
}

static uint32_t	julia_color(int iter, fractal_t *f)
{
	double			t;
	uint8_t			intensity;
	static uint32_t	colors[8] = {RED, ORANGE, YELLOW, GREEN,
		CYAN, BLUE, MAGENTA, PURPLE};

	if (iter == MAX_ITERATIONS)
	{
		if (f->flag.invert)
			return (WHITE);
		return (BLACK);
	}
	t = (double)iter / MAX_ITERATIONS;
	intensity = 255 * t;
	if (f->flag.invert)
		intensity = 255 - intensity;
	if (f->flag.monochrome)
		return (get_mono_colors_julia(intensity));
	return (colors[iter % 8]);
}

int	julia_iter(double zx, double zy, fractal_t *f)
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



void	draw_julia(fractal_t *f)
{
	int		x;
	int		y;
	double	zx;
	double	zy;
	int		iter;

	y = 0;
	if (!f->img)
		f->img = mlx_new_image(f->mlx, f->w_size.width, f->w_size.height);
	while (y < f->w_size.height)
	{
		x = 0;
		while (x < f->w_size.width)
		{
			zx = (x - f->w_size.width / 2.0) / (0.5 * f->zoom * f->w_size.width) + f->x;
			zy = (y - f->w_size.height / 2.0) / (0.5 * f->zoom * f->w_size.height) + f->y;
			iter = julia_iter(zx, zy, f);
			mlx_put_pixel(f->img, x, y,
				julia_color(iter, f));
			x++;
		}
		y++;
	}
}
