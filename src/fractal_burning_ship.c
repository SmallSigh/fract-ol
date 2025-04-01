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

void	draw_burning_ship(t_fractal *f)
{
	int		x;
	int		y;
	double	cr;
	double	ci;

	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->w_size.width, f->w_size.height);
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
				fractal_color(burning_ship_iter(cr, ci), f));
			x++;
		}
		y++;
	}
}
