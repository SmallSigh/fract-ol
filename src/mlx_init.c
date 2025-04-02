/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:05 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 18:00:06 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	print_error_and_exit(char *str)
{
	ft_printf("ERROR: %s", str);
}

void	init_fractal(t_fractal *f)
{
	f->zoom = 1.0;
	f->x = 0;
	f->y = 0;
	f->color = BLACK;
	f->img = NULL;
	f->julia.c_real = 0.7;
	f->julia.c_imag = 0.27;
}

void	choose_window_size(t_fractal *f)
{
	int32_t	width;
	int32_t	height;

	f->w_size.height = HEIGHT;
	f->w_size.width = WIDTH;
	f->mlx = mlx_init(WIDTH, HEIGHT, "Small Fractol", false);
	if (!f->mlx)
		cleanup(f);
	if (f->flag.maximize)
	{
		mlx_get_monitor_size(0, &width, &height);
		f->w_size.height = height;
		f->w_size.width = width;
		mlx_set_window_size(f->mlx, f->w_size.width, f->w_size.height);
		mlx_set_window_pos(f->mlx, 0, 0);
	}
}

void	start_mlx(t_fractal *f)
{
	choose_window_size(f);
	mlx_key_hook(f->mlx, ft_hook, f);
	mlx_scroll_hook(f->mlx, ft_scrollhook, f);
	init_fractal(f);
}

void	cleanup(t_fractal *f)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx->window)
		mlx_close_window(f->mlx);
	if (f->mlx)
		mlx_terminate(f->mlx);
}
