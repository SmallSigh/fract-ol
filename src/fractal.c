/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:45 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 22:35:52 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	render(t_fractal *f)
{
	int x;
	int y;

	if (f->img)
		ft_bzero(f->img->pixels,
			f->img->width * f->img->height * sizeof(uint8_t));
	y = 0;
	while (y < f->mlx->height)
	{
		x = 0;
		while (x < f->mlx->width)
		{
			if (f->fractal_type == MANDELBROT)
				draw_mandelbrot(f, x, y);
			else if (f->fractal_type == BURNING_SHIP)
				draw_burning_ship(f, x, y);
			else if (f->fractal_type == JULIA)
				draw_julia(f, x, y);
			x++;
		}
		y++;
	}
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
