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

int	mandelbrot(double complex c)
{
	double complex	z;
	int				iter;

	z = 0;
	iter = 0;
	while (iter < MAX_ITERATIONS)
	{
		if (creal(z) > 4)
			return (iter);
		z = z * z + c;
		iter++;
	}
	return (iter);
}

// 80 for width
// 40 for heigth
// 10 for max iterations
void	draw_mandelbrot_illegal(void)
{
	int		x;
	int		y;
	double	real;
	double	imag;
	int		iter;

	y = 0;
	while (y < 40)
	{
		x = 0;
		while (x < 80)
		{
			real = (x - 80 / 2) * 4.0 / 80;
			imag = (y - 40 / 2) * 4.0 / 40;
			iter = mandelbrot(real + imag * I);
			if (iter == MAX_ITERATIONS)
				ft_printf("*");
			else
				ft_printf(" ");
			x++;
		}
		ft_printf("\n");
		y++;
	}
}

void	illegal_check(fractal_t *f)
{
	if (f->flag.terminal == true)
	{
		draw_mandelbrot_illegal();
		cleanup(f);
		exit (EXIT_SUCCESS);
	}
}

void	render(fractal_t *f)
{
	illegal_check(f);
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
