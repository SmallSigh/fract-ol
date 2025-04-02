/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_header.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:05 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 23:10:39 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "MLX42/MLX42.h"
# include "../lib/MLX42/include/MLX42/MLX42_Int.h"
# include "defines.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <complex.h>

typedef enum e_fractalype
{
	MANDELBROT = 1,
	BURNING_SHIP,
	JULIA
}	e_fractaltype;

typedef struct flags_s
{
	bool	maximize;
	bool	invert;
	bool	monochrome;
}			t_flags;

typedef struct julia_s
{
	double	c_real;
	double	c_imag;
}			t_julia;

typedef struct s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_t			*win;
	double			zoom;
	double			x;
	double			y;
	uint32_t		color;
	e_fractaltype	fractal_type;
	t_flags			flag;
	t_julia			julia;
}					t_fractal;

// mlx stuff
void		start_mlx(t_fractal *f);
void		cleanup(t_fractal *f);
void		ft_keypress_hook(mlx_key_data_t key_data, void *param);
void		ft_scrollhook(double xdelta, double ydelta, void *param);
void		ft_hold_key(void *param);

//  parse attempt
void		user_input(int ac, char **av, t_fractal *f);
void		entry_guide(void);

// the rendering
void		render(t_fractal *f);
void		init_fractal(t_fractal *f);
uint32_t	fractal_color(int iter, t_fractal *f);

// the fractal
void		draw_mandelbrot(t_fractal *, uint32_t x, uint32_t y);
void		draw_burning_ship(t_fractal *, uint32_t x, uint32_t y);
void		draw_julia(t_fractal *, uint32_t x, uint32_t y);

// leftover utils
int			is_valid_mouse_pos(int mouse_x, int mouse_y, t_fractal *f);
void		reset_julia_vars(t_fractal *f);
void		my_draw_pixel(uint8_t *pixel, uint32_t color);

#endif