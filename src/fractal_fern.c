/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_fern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:05 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 17:16:43 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

// TODO, fix flags for fern

// updates either stem, left leaf, right leaf, or
static void	update_image(double *x, double *y, double random)
{
	double	new_x;
	double	new_y;

	if (random < 0.01)
	{
		new_x = 0.0;
		new_y = 0.16 * *y;
	}
	else if (random < 0.86)
	{
		new_x = 0.85 * *x + 0.04 * *y;
		new_y = -0.04 * *x + 0.85 * *y + 1.6;
	}
	else if (random < 0.93)
	{
		new_x = 0.2 * *x - 0.26 * *y;
		new_y = 0.023 * *x + 0.22 * *y + 1.6;
	}
	else
	{
		new_x = -0.15 * *x + 0.28 * *y;
		new_y = 0.26 * *x + 0.24 * *y;
	}
	*x = new_x;
	*y = new_y;
}

void	fern_cleanup(double *x, double *y, t_fractal *f)
{
	mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->w_size.width, f->w_size.height);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
	*x = f->x;
	*y = f->y;
}

uint32_t	get_color_fern(t_fractal *f)
{
	if (f->flag.invert == true)
	{
		if (f->flag.monochrome == true)
			return (GREY_2);
		return (PURPLE);
	}
	if (f->flag.monochrome == true)
		return (GREY_8);
	return (GREEN);
}

// checks if pixel x or pixel y is in window or outside of window
int	is_in_window(int pixel_x_pos, int pixel_y_pos, t_fractal *f)
{
	if (pixel_x_pos >= 0 && pixel_y_pos >= 0 && pixel_x_pos < f->w_size.width
		&& pixel_y_pos < f->w_size.height)
		return (1);
	return (0);
}

void	draw_fern(t_fractal *f)
{
	double	x;
	double	y;
	int		iter;
	int		px;
	int		py;

	fern_cleanup(&x, &y, f);
	iter = 0;
	while (iter < FERN_ITERATIONS)
	{
		update_image(&x, &y, (double)rand() / (double)RAND_MAX);
		px = (int)((x - f->x) * f->w_size.width / 10 + f->w_size.width / 2);
		py = (int)f->w_size.height - ((y - f->y) * f->w_size.height / 10);
		if (is_in_window(px, py, f))
			mlx_put_pixel(f->img, px, py, get_color_fern(f));
		iter++;
	}
}
