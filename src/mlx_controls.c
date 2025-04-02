/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:25 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 23:19:16 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

static void	zoom_at_position(t_fractal *f, double zoom_factor,
	int mouse_x, int mouse_y)
{
	double	mouse_r;
	double	mouse_i;
	double	new_center_r;
	double	new_center_i;
	double	prev_zoom;

	mouse_r = (mouse_x - f->img->width / 2.0)
		* 4.0 / (f->img->width * f->zoom) + f->x;
	mouse_i = (mouse_y - f->img->height / 2.0)
		* 4.0 / (f->img->height * f->zoom) + f->y;
	new_center_r = f->x + (mouse_r - f->x) * (1 - 1 / zoom_factor);
	new_center_i = f->y + (mouse_i - f->y) * (1 - 1 / zoom_factor);
	prev_zoom = f->zoom;
	f->zoom *= zoom_factor;
	if (f->zoom < 0.0001)
		f->zoom = 0.0001;
	if (f->zoom > 10000000)
		f->zoom = 10000000;
	if (f->zoom != prev_zoom)
	{
		f->x = new_center_r;
		f->y = new_center_i;
	}
}

void	ft_scrollhook(double scrolldown, double scrollup, void *param)
{
	t_fractal	*f;
	int32_t		mouse_x;
	int32_t		mouse_y;
	double		zoom_factor;

	(void)scrolldown;
	f = (t_fractal *)param;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (scrollup > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	zoom_at_position(f, zoom_factor, mouse_x, mouse_y);
	render(f);
}

void	julia_controls_press(mlx_key_data_t key_data, t_fractal *f)
{
	double			update_julia;
	double			update_julia_little;

	update_julia = 0.01;
	update_julia_little = 0.001;
	if (key_data.key == MLX_KEY_UP)
		f->julia.c_imag += update_julia;
	if (key_data.key == MLX_KEY_DOWN)
		f->julia.c_imag -= update_julia;
	if (key_data.key == MLX_KEY_RIGHT)
		f->julia.c_real += update_julia;
	if (key_data.key == MLX_KEY_LEFT)
		f->julia.c_real -= update_julia;
	if (key_data.key == MLX_KEY_W)
		f->julia.c_imag += update_julia_little;
	if (key_data.key == MLX_KEY_S)
		f->julia.c_imag -= update_julia_little;
	if (key_data.key == MLX_KEY_D)
		f->julia.c_real += update_julia_little;
	if (key_data.key == MLX_KEY_A)
		f->julia.c_real -= update_julia_little;
}

void	julia_controls_hold(t_fractal *f)
{
	double			update_julia;
	double			update_julia_little;

	update_julia = 0.01;
	update_julia_little = 0.001;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP))
		f->julia.c_imag += update_julia;
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN))
		f->julia.c_imag -= update_julia;
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT))
		f->julia.c_real += update_julia;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT))
		f->julia.c_real -= update_julia;
	if (mlx_is_key_down(f->mlx, MLX_KEY_W))
		f->julia.c_imag += update_julia_little;
	if (mlx_is_key_down(f->mlx, MLX_KEY_S))
		f->julia.c_imag -= update_julia_little;
	if (mlx_is_key_down(f->mlx, MLX_KEY_D))
		f->julia.c_real += update_julia_little;
	if (mlx_is_key_down(f->mlx, MLX_KEY_A))
		f->julia.c_real -= update_julia_little;
}

void	ft_hold_key(void *param)
{
	t_fractal	*f;

	f = param;
	if (f->fractal_type == JULIA)
		julia_controls_hold(f);
	render(f);
}
