/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:23:45 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 15:13:48 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	render(t_fractal *f)
{
	if (f->type.mandelbrot == true)
		draw_mandelbrot(f);
	if (f->type.burning_ship == true)
		draw_burning_ship(f);
	if (f->type.julia == true)
		draw_julia(f);
	mlx_image_to_window(f->mlx, f->img, 0, 0);
}
