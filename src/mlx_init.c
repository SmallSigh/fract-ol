/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:13:05 by masmit            #+#    #+#             */
/*   Updated: 2025/03/27 14:49:29 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	print_error_and_exit(char *str)
{
	ft_printf("ERROR: %s", str);
}

void	choose_window_size(fractal_t *f)
{
	int32_t	width;
	int32_t	height;

	f->w_size.height = HEIGHT;
	f->w_size.width = WIDTH;
	f->mlx = mlx_init(WIDTH, HEIGHT, "small fractol", false);
	if (f->flag.maximize)
	{
		mlx_get_monitor_size(0, &width, &height);
		mlx_set_window_size(f->mlx, width, height);
		f->w_size.height = height;
		f->w_size.width = width;
		mlx_terminate(f->mlx);
		f->mlx = mlx_init(width, height, "Big Fractol", true);
	}
}

void	start_mlx(fractal_t *f)
{
	choose_window_size(f);
	mlx_key_hook(f->mlx, ft_hook, f);
	mlx_scroll_hook(f->mlx, ft_scrollhook, f);
}

void	cleanup(fractal_t *f)
{
	if (f->img)
		mlx_delete_image(f->mlx, f->img);
	if (f->mlx)
		mlx_terminate(f->mlx);
}
