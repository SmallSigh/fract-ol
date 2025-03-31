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


static uint32_t	get_fern_color(int iter, fractal_t *f)
{
	double			t;
	uint8_t			intensity;
	static uint32_t	colors[8] = {GREEN, YELLOW, ORANGE, RED,
		PURPLE, MAGENTA, BLUE, CYAN};

	if (iter == 5000)
	{
		if (f->flag.invert)
			return (WHITE);
		return (BLACK);
	}
	t = (double)iter / 5000;
	intensity = 255 * t;
	if (f->flag.invert)
		intensity = 255 - intensity;
	if (f->flag.monochrome)
		return (SET_MONO(intensity));
	return (colors[iter % 8]);
}

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
		new_x = 0.-15 * *x + 0.28 * *y;
		new_y = 0.26 * *x + 0.24 * *y;
	}
	*x = new_x;
	*y = new_y;
}

void	draw_fern(fractal_t *f)
{
	double	x;
	double	y;
	int		iter;
	int		px;
	int		py;
	
	x = 0;
	y = 0;
	iter = 0;
	while (iter < 5000)
	{
		update_image(&x, &y, (double)rand() / INT_MAX);
		px = (int)(x * f->zoom * f->w_size.width / 10 + f->w_size.width / 2);
		py = (int)(y * f->zoom * f->w_size.height / 10 + f->w_size.height / 2);
		if (px >= 0 && px < f->w_size.width
			&& py < f->w_size.height)
			mlx_put_pixel(f->img, px, py, get_fern_color(iter, f));
		iter++;
	}
}