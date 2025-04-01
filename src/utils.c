/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:19:15 by masmit            #+#    #+#             */
/*   Updated: 2025/03/26 16:30:01 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	init_fractal_bools(t_fractal *f)
{
	f->type.mandelbrot = false;
	f->type.burning_ship = false;
	f->type.julia = false;
	f->type.barnsley_fern = false;
}

void	init_flag_bools(t_fractal *f)
{
	f->flag.invert = false;
	f->flag.maximize = false;
	f->flag.monochrome = false;
	f->flag.terminal = false;
}
