/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:45 by masmit            #+#    #+#             */
/*   Updated: 2025/03/26 17:25:59 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	init_fractal(fractal_t *f, int type)
{
	f->zoom = 1.0;
	f->x = 0;
	f->y = 0;
	f->max_iter = MAX_ITERATIONS;
	f->type = type;
	f->color = BLACK;
	f->mlx = NULL;
	f->img = NULL;
}
// void	render(fractal_t *f)
// {
// 	if (f->type == MANDELBROT)
// 		draw_mandelbrot(f);
// 	else if (f->type == BURNING_SHIP)
// 		draw_burning_ship(f);
// 	else if (f->type == SIERPINSKY)
// 		draw_sierpinsky(f);
// 	else if (f->type == BARNSLEY_FERN)
// 		draw_fern(f);
// 	return;
// }
