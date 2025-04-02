/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:45 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 16:42:09 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	render(t_fractal *f)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->w_size.width, f->w_size.height);
	if (!f->img)
		cleanup(f);
	if (f->type.mandelbrot == true)
		draw_mandelbrot(f);
	if (f->type.burning_ship == true)
		draw_burning_ship(f);
	if (f->type.julia == true)
		draw_julia(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
