/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_fern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:05 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 17:16:43 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HEADER_H
# define MAIN_HEADER_H

# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "MLX42/MLX42.h"
# include "defines.h"

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <complex.h>

// mandelbrot formula = z_real² + z_imag²
// burning ship formula = z=abs(z)^2+c
// sierpinsky formula = n=m^d
// not a formula, uses a % of number generation to update eiter stem or leaves

typedef struct s_fractalype
{
	bool	mandelbrot;
	bool	burning_ship;
	bool	julia;
}	t_fractal_type;

typedef struct window_size_s
{
	int32_t	width;
	int32_t	height;
}			t_window_size;

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

/*main struct in code*/
/*x = offset x, where on the x axis we render the pixels
this axis is rendered with real numbers*/
/*y = offset y, which is an axis of imaginary numbers numbers
such as z or i*/

typedef struct s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_t			*win;
	double			zoom;
	double			x;
	double			y;
	t_fractal_type	type;
	uint32_t		color;
	t_flags			flag;
	t_window_size	w_size;
	t_julia			julia;
}					t_fractal;

// mlx stuff
void		start_mlx(t_fractal *f);
void		cleanup(t_fractal *f);
void		ft_hook(mlx_key_data_t key_data, void *param);
void		ft_scrollhook(double xdelta, double ydelta, void *param);

//  parse attempt
void		user_input(int ac, char **av, t_fractal *f);
void		entry_guide(void);

// init bools as false
void		init_flag_bools(t_fractal *f);
void		init_fractal_bools(t_fractal *f);

// the rendering
void		render(t_fractal *f);
void		init_fractal(t_fractal *f);
uint32_t	fractal_color(int iter, t_fractal *f);

// the fractal
void		draw_mandelbrot(t_fractal *f);
void		draw_burning_ship(t_fractal *f);
void		draw_fern(t_fractal *f);
void		draw_julia(t_fractal *f);

// leftover utils
int			valid_mouse_pos(int mouse_x, int mouse_y, t_fractal *f);
void		reset_julia_vars(t_fractal *f);

#endif