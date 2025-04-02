/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:05 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 23:26:24 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	init_fractal(t_fractal *f)
{
	f->zoom = 1.0;
	f->color = BLACK;
	f->julia.c_real = 0.7;
	f->julia.c_imag = 0.27;
}

void	choose_window_size(t_fractal *f)
{
	int32_t	width;
	int32_t	height;

	f->mlx = mlx_init(WIDTH, HEIGHT, "Small Fractol", false);
	if (!f->mlx)
		cleanup(f);
	if (f->flag.maximize)
	{
		mlx_get_monitor_size(0, &width, &height);
		mlx_set_window_size(f->mlx, width, height);
		mlx_set_window_pos(f->mlx, 0, 0);
	}
}

void	start_mlx(t_fractal *f)
{
	choose_window_size(f);
	f->img = mlx_new_image(f->mlx, f->mlx->width, f->mlx->height);
	if (!f->img)
		cleanup(f);
	init_fractal(f);
	mlx_key_hook(f->mlx, ft_keypress_hook, f);
	mlx_scroll_hook(f->mlx, ft_scrollhook, f);
	mlx_loop_hook(f->mlx, ft_hold_key, f);
}

void	cleanup(t_fractal *f)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx->window)
		mlx_close_window(f->mlx);
	if (f->mlx)
		mlx_terminate(f->mlx);
	exit(EXIT_SUCCESS);
}

void	ft_keypress_hook(mlx_key_data_t key_data, void *param)
{
	t_fractal	*f;

	f = param;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->mlx);
		if (f->fractal_type == JULIA)
			julia_controls_press(key_data, f);
		if (key_data.key == MLX_KEY_R)
			reset_julia_vars(f);
		render(f);
	}
}
