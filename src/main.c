/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:29 by masmit            #+#    #+#             */
/*   Updated: 2025/03/22 18:12:10 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

#define MAX_ITERATIONS 100

int	get_color(int iterations)
{
		int colors[] = {
			RED,
			GREEN,
			BLUE,
			YELLOW,
			CYAN,
			MAGENTA,
			ORANGE,
			PURPLE,
			WHITE,
			BLACK
	};
	if (iterations == MAX_ITERATIONS)
		return (BLACK);
	return colors[iterations % 10];
}

// explain complex numbers eg. z
// ib = in_bounds
int	draw_mandelbrot(double real, double imaginary)
{
	double ib;
	double n_real;
	double temp;
	int iteration;

	iteration = 0;
	ib = 0;
	n_real = 0;
	while ((ib * ib + n_real * n_real <= 4) && iteration < MAX_ITERATIONS)
	{
		temp = ib * ib - n_real * n_real + real;
		imaginary = 2 * ib * n_real * imaginary;
		ib = temp;
		iteration++;
	}
	return (iteration);
}

void	compute_coords(t_fractol *fractol, double *real, double *imaginary)
{
	*real = (fractol->x - WIDTH / 2.0);
	*real = *real * fractol->zoom + fractol->offsetX;
	*imaginary = (fractol->y - HEIGHT / 2.0);
	*imaginary = *imaginary *fractol->zoom + fractol->offsetY;
}

void	draw_fractol(t_fractol *fractol)
{
	double	real_part;
	double imaginary_part;
	int iterations;
	int color;

	fractol->y = 0;
	while (fractol->y < HEIGHT)
	{
	fractol->x = 0;
		while (fractol->x < WIDTH)
		{
			compute_coords(fractol, &real_part, &imaginary_part);
			iterations = draw_mandelbrot(real_part, imaginary_part);
			color = get_color(iterations);
			mlx_put_pixel(fractol->img, fractol->x, fractol->y, color);
			fractol->x++;
		}
		fractol->y++;
	}
}

void	fractol_init(t_fractol *fractol, mlx_t *mlx)
{
	fractol->zoom = 4.0 / WIDTH;
	fractol->offsetX = -2.0;
	fractol->offsetY = -2.0;
	fractol->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!fractol->img)
		exit (1);
}

void	mlx_key_hook(mlx_key_data_t *mlx_key_data, void *param)
{
	t_fractol *fractol;
	fractol = (t_fractol *)param;

	(void)mlx_key_data;
	// if (mlx_key_data.action == MLX_RELEASE)
	// 	return;
	// if (mlx_key_data.key == MLX_KEY_UP)
	// 	fractol->offsetY -= fractol->zoom * 20;
	// if (mlx_key_data.key == MLX_KEY_DOWN)
	// 	fractol->offsetY += fractol->zoom * 20;
	// if (mlx_key_data.key == MLX_KEY_LEFT)
	// 	fractol->offsetX -= fractol->zoom * 20;
	// if (mlx_key_data.key == MLX_KEY_RIGHT)
	// 	fractol->offsetX += fractol->zoom * 20;
	// if (mlx_key_data.key == MLX_KEY_EQUAL)
	// 	fractol->zoom *= 0.9;
	// if (mlx_key_data.key == MLX_KEY_MINUS)
	// 	fractol->zoom /= 0.9;

	draw_fractol(fractol);
}

int	main(void)
{
	mlx_t		*mlx;
	t_fractol	fractol;

	mlx = mlx_init(WIDTH, HEIGHT, "fractol", true);
	if (!mlx)
		return (1);
	fractol_init(&fractol, mlx);
	mlx_image_to_window(mlx, fractol.img, 0, 0);
	draw_fractol(&fractol);
	mlx_key_hook(mlx, &fractol);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
