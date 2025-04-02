/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:19:15 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 23:03:25 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	reset_julia_vars(t_fractal *f)
{
	f->zoom = 1.0;
	f->x = 0;
	f->y = 0;
	f->color = BLACK;
	f->julia.c_real = 0.7;
	f->julia.c_imag = 0.27;
}

int	is_valid_mouse_pos(int mouse_x, int mouse_y, t_fractal *f)
{
	if (mouse_x > f->win->width || mouse_x < 0)
		return (false);
	if (mouse_y > f->win->height || mouse_y < 0)
		return (false);
	return (true);
}

void	my_draw_pixel(uint8_t *pixel, uint32_t color)
{
	*(uint32_t *)pixel = color;
}
