/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_mandelbrot.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:33:11 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 14:03:06 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

uint32_t	get_mono_colors(int intensity)
{
	return (SET_MONO((uint8_t)intensity));
}

static uint32_t	mandelbrot_color(int iter, fractal_t *f)
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
		return (get_mono_colors(intensity));
	return (colors[iter % 8]);
}

static int	mandelbrot_iter(double cr, double ci)
{
	double	zr;
	double	zi;
	double	temp;
	int		iter;

	zr = 0;
	zi = 0;
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (zr * zr + zi * zi > 4.0)
			break ;
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		iter++;
	}
	return (iter);
}

void	draw_mandelbrot(fractal_t *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	y = 0;
	f->img = mlx_new_image(f->mlx, f->w_size.width, f->w_size.height);
	while (y < f->w_size.height)
	{
		x = 0;
		while (x < f->w_size.width)
		{
			cr = (x - f->w_size.width / 2.0) * 4.0
				/ (f->w_size.width * f->zoom) + f->x;
			ci = (y - f->w_size.height / 2.0) * 4.0
				/ (f->w_size.height * f->zoom) + f->y;
			mlx_put_pixel(f->img, x, y,
				mandelbrot_color(mandelbrot_iter(cr, ci), f));
			x++;
		}
		y++;
	}
}
