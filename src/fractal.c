/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:45 by masmit            #+#    #+#             */
/*   Updated: 2025/03/27 14:16:57 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	init_f_fractal(fractal_t *f)
{
	f->zoom = 1.0;
	f->x = 0;
	f->y = 0;
	f->color = BLACK;
	f->img = NULL;
}

void	draw_sierpinsky(fractal_t *f)
{
	(void)f;
}

void	draw_fern(fractal_t *f)
{
	(void)f;
}

void	render(fractal_t *f)
{
	init_f_fractal(f);
	f->img = mlx_new_image(f->mlx, f->w_size.width, f->w_size.height);
	if (f->type.MANDELBROT == true)
		draw_mandelbrot(f);
	if (f->type.BURNING_SHIP == true)
		draw_burning_ship(f);
	if (f->type.SIERPINSKY == true)
		draw_sierpinsky(f);
	if (f->type.BARNSLEY_FERN == true)
		draw_fern(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
