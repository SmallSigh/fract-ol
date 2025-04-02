/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:05 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 22:16:45 by masmit           ###   ########.fr       */
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

	colors[0] = PURPLE_1;
	colors[1] = BLUE_1;
	colors[2] = BLUE_2;
	colors[3] = BLUE_PURPLE;
	colors[4] = PURPLE_BLUE;
	colors[5] = PURPLE_2;
	colors[6] = PURPLE_3;
	colors[7] = PURPLE_4;
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
