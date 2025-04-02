/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_burning_ship.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:15:59 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 23:04:47 by masmit           ###   ########.fr       */
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

void	draw_burning_ship(t_fractal *f, uint32_t x, uint32_t y)
{
	double	cr;
	double	ci;

	cr = (x - f->mlx->width / 2.0)
		* 4.0 / (f->mlx->width * f->zoom) + f->x;
	ci = (y - f->mlx->height / 2.0)
		* 4.0 / (f->mlx->height * f->zoom) + f->y;
	my_draw_pixel(f, x, y, fractal_color(burning_ship_iter(cr, ci), f));
}
