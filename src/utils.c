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

void	my_draw_pixel(t_fractal *f, uint32_t x, uint32_t y, uint32_t color)
{
	uint32_t	*pixel_pos;

	pixel_pos = (uint32_t *)&f->img->pixels
	[(y * f->img->width + x) * sizeof(int32_t)];
	*(uint32_t *)pixel_pos = color;
}

void	print_error_and_exit(char *str)
{
	ft_printf("ERROR: %s", str);
}
