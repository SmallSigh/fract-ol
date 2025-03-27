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

void	init_fractal_bools(fractal_t *f)
{
	f->type.MANDELBROT = false;
	f->type.BURNING_SHIP = false;
	f->type.SIERPINSKY = false;
	f->type.BARNSLEY_FERN = false;
}

void	init_flag_bools(fractal_t *f)
{
	f->flag.invert = false;
	f->flag.maximize = false;
	f->flag.monochrome = false;
	f->flag.terminal = false;
}
