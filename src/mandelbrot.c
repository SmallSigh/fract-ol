/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:33:11 by masmit            #+#    #+#             */
/*   Updated: 2025/03/26 16:18:50 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

uint32_t get_mono_colors(colors, color, intensity)
{
	// TODO;
}

static uint32_t	mandelbrot_color(int iter,fractal_t *f)
{
	double t;
	uint8_t intensity;
	uint32_t	color;
	static uint32_t colors[8] =	{RED, ORANGE, YELLOW, GREEN,
								CYAN, BLUE, MAGENTA, PURPLE };
	if (iter == MAX_ITERATIONS)
	{
		if (f->flag.invert)
			return (WHITE);
		return (BLACK);
	}
	if (f->flag.monochrome)
	{
		t = (double)iter / MAX_ITERATIONS;
		intensity = 255 * t;
		if (f->flag.invert)
			intensity = 255 - intensity;
		color = get_mono_colors(colors, color, intensity);
		return (color);
	}
	return (colors[iter % 8]);
}

static int	mandelbrot_iter(double cr, double ci)
{
	double zr;
	double zi;
	double temp;
	int iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		while (zr * zr + zi * zi <= 4.0)
		{
			temp = zr * zr - zi * zi + cr;
			zi = 2 * zr * zi + ci;
			zr = temp;
			iter++;
		}
	}
	return (iter);
}

void	draw_mandelbrot(fractal_t *f)
{
	int x;
	int y;
	int iter;
	double cr;
	double ci;

	y = 0;
	while (y < f->img->height)
	{
		x = 0;
		while (x < f->img->width)
		{
			cr = (x - f->img->width / 2.0) * 4.0 / (f->img->width * f->zoom) + f->x;
			ci = (x - f->img->height / 2.0) * 4.0 / (f->img->height * f->zoom) + f->y;
			iter = mandelbrot_iter(cr, ci);
			mlx_put_pixel(f->img, x, y, mandelbrot_color(iter, f));
			x++;
		}
		y++;
	}
}
