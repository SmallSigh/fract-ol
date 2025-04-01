/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:25 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 14:19:59 by masmit           ###   ########.fr       */
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

	mouse_r = (mouse_x - f->w_size.width / 2.0)
		* 4.0 / (f->w_size.width * f->zoom) + f->x;
	mouse_i = (mouse_y - f->w_size.height / 2.0)
		* 4.0 / (f->w_size.height * f->zoom) + f->y;
	new_center_r = f->x + (mouse_r - f->x) * (1 - 1 / zoom_factor);
	new_center_i = f->y + (mouse_i - f->y) * (1 - 1 / zoom_factor);
	f->x = new_center_r;
	f->y = new_center_i;
	f->zoom *= zoom_factor;
	if (f->zoom < 0.1)
		f->zoom = 0.1;
	if (f->zoom > 10000000)
		f->zoom = 10000000;
}

void	ft_scrollhook(double scrolldown, double scrollup, void *param)
{
	t_fractal	*f;
	int			mouse_x;
	int			mouse_y;
	double		zoom_factor;

	(void)scrolldown;
	f = (t_fractal *)param;
	mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (valid_mouse_pos(mouse_x, mouse_y, f))
		return ;
	if (scrollup > 0)
		zoom_factor = 1.1;
	else
		zoom_factor = 0.9;
	zoom_at_position(f, zoom_factor, mouse_x, mouse_y);
	render(f);
}

void	secret_julia_controls(mlx_key_data_t key_data, t_fractal *f)
{
	double			update_julia;
	double			update_julia_little;
	int				readability_________________split;

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
	(void)readability_________________split;
	if (key_data.key == MLX_KEY_W)
		f->julia.c_imag += update_julia_little;
	if (key_data.key == MLX_KEY_S)
		f->julia.c_imag -= update_julia_little;
	if (key_data.key == MLX_KEY_D)
		f->julia.c_real += update_julia_little;
	if (key_data.key == MLX_KEY_A)
		f->julia.c_real -= update_julia_little;
}

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	t_fractal	*f;

	f = param;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->mlx);
		if (f->type.julia == true)
			secret_julia_controls(key_data, f);
		if (key_data.key == MLX_KEY_R)
			reset_julia_vars(f);
		render(f);
	}
}
