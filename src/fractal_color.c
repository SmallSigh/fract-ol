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

uint32_t	get_mono(uint8_t iter, t_fractal *f)
{
	uint32_t	colors[10];

	colors[0] = GREY_1;
	colors[1] = GREY_2;
	colors[2] = GREY_3;
	colors[3] = GREY_4;
	colors[4] = GREY_5;
	colors[5] = GREY_6;
	colors[6] = GREY_7;
	colors[7] = GREY_8;
	colors[8] = GREY_9;
	colors[9] = GREY_10;
	if (f->flag.invert == true)
		return (colors[10 - (iter % 10)]);
	return (colors[iter % 10]);
}

uint32_t	fractal_color(int iter, t_fractal *f)
{
	uint32_t	colors[8];

	colors[0] = RED;
	colors[1] = GREEN;
	colors[2] = BLUE;
	colors[3] = YELLOW;
	colors[4] = CYAN;
	colors[5] = MAGENTA;
	colors[6] = PURPLE;
	colors[7] = ORANGE;
	if (iter == MAX_ITERATIONS)
	{
		if (f->flag.invert == true)
			return (WHITE);
		return (BLACK);
	}
	if (f->flag.monochrome == true)
		return (get_mono(iter, f));
	if (f->flag.invert == true)
		return (colors[8 - (iter % 8)]);
	return (colors[iter % 8]);
}
