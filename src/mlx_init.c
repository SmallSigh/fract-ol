/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:05 by masmit            #+#    #+#             */
/*   Updated: 2025/03/26 17:17:09 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	fractal_t *f;

	f = param;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->mlx);
		if (key_data.key == MLX_KEY_UP)
			ft_printf("up key has been pressed\n");
		if (key_data.key == MLX_KEY_DOWN)
			ft_printf("down key has been pressed\n");
	}
}

void	print_error_and_exit(char *str)
{
	ft_printf("ERROR: %s", str);
	exit (1);
}

void	choose_window_size(fractal_t *f)
{
	int32_t width;
	int32_t height;

	if (f->flag.maximize)
	{
		mlx_get_monitor_size(0, &width, &height);
		mlx_set_window_size(f->mlx, width, height);
		f->mlx->height = height;
		f->mlx->width = width;
		f->mlx = mlx_init(width, height, "Big Fractol", false);
		f->img = mlx_new_image(f->mlx, width, height);
	}
	else
	{
		f->mlx->height = WIDTH;
		f->mlx->width = HEIGHT;
		f->mlx = mlx_init(WIDTH, HEIGHT, "small fractol", false);
		f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	}
	if (!f->mlx)
		print_error_and_exit("failed to initialize mlx window.\n");
	if (!f->img)
		print_error_and_exit("failed to put image to window.\n");
}

void	start_mlx(fractal_t *f)
{
	choose_window_size(f);
	mlx_key_hook(f->mlx, ft_hook, f);
}

void	cleanup(fractal_t *f)
{
	if (f->mlx != NULL)
		mlx_terminate(f->mlx);
}
