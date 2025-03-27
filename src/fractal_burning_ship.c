/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burning_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:15:59 by masmit            #+#    #+#             */
/*   Updated: 2025/03/27 14:40:12 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

static int	burning_ship_iter(double cr, double ci)
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
		zi = fabs(2 * zr * zi) + ci;
		zr = fabs(temp);
		iter++;
	}
	return (iter);
}

static uint32_t	burning_ship_color(int iter, fractal_t *f)
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
	intensity = (uint8_t)(255 * t);
	if (f->flag.invert)
		intensity = 255 - intensity;
	if (f->flag.monochrome)
		return (SET_MONO(intensity));
	return (colors[iter % 8]);
}

void	draw_burning_ship(fractal_t *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	y = 0;
	while (y < f->w_size.height)
	{
		x = 0;
		while (x < f->w_size.width)
		{
			cr = (x - f->w_size.width / 2.0)
				* 4.0 / (f->w_size.width * f->zoom) + f->x;
			ci = (y - f->w_size.height / 2.0)
				* 4.0 / (f->w_size.height * f->zoom) + f->y;
			mlx_put_pixel(f->img, x, y,
				burning_ship_color(burning_ship_iter(cr, ci), f));
			x++;
		}
		y++;
	}
}
