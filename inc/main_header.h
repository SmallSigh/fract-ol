#ifndef MAIN_HEADER_H
 #define MAIN_HEADER_H

 #include "../lib/gnl/get_next_line.h"
 #include "../lib/libft/libft.h"
 #include "../lib/ft_printf/ft_printf.h"
 #include "MLX42/MLX42.h"

 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <math.h>
 #include <complex.h>

 #define BLACK		0x000000FF
 #define WHITE		0xFFFFFF00
 #define RED		0xFF0000FF
 #define GREEN		0x00FF00FF
 #define BLUE		0x0000FFFF
 #define YELLOW		0xFFFF00FF
 #define CYAN		0x00FFFF00
 #define MAGENTA	0xFF00FFFF
 #define ORANGE		0xFFA500FF
 #define PURPLE		0x800080FF

 #define DEBUG ft_printf("%s, %d"__FILE__, __LINE__)

//  for monochrome
// grey is in different brigtness, 0xFF for white
// 16 for red to grey
// 8 for green to grey
// nothing for blue to grey

#define SET_MONO(gray)	((0xFF << 24) |\
						 ((gray) << 16) |\
						 ((gray) << 8) |\
						 (gray))

 #define WIDTH 1080
 #define HEIGHT 1080
 #define MAX_ITERATIONS 100

 #define INSTRUCTIONS "\n\n\
 \
Usage: ./fractal [(fractal 1-4)] [flags]\n\n\
Fractals:\n\
	\t1. Mandelbrot\n\
	\t2. Burning Ship\n\
	\t3. Sierpinski/Zelda\n\
	\t4. Barnsley Fern\n\n\
Flags:\n\
	\t-f for fullscreen window\n\
	\t-b for black and white colours\n\
	\t-c for inverted colours\n\
	\t-t for fractal in terminal, WIP, only for mandelbrot\n"

// mandelbrot formula = z_real² + z_imag²
// burning ship formula = z=abs(z)^2+c
// sierpinsky formula = n=m^d
// not a formula, uses a % of number generation to update eiter stem or leaves

typedef struct fractal_type_s
{
	bool	MANDELBROT;
	bool	BURNING_SHIP;
	bool	SIERPINSKY;
	bool	BARNSLEY_FERN;
}	fractal_type_t;

#define FLAG_MAXIMIZE		"-f"
#define FLAG_BLACK_WHITE	"-b"
#define FLAG_INVERT			"-c"
#define FLAG_TERMINAL		"-t"

/*main struct in code*/
/*x = offset x, where on the x axis we render the pixels
this axis is rendered with real numbers*/
/*y = offset y, which is an axis of imaginary numbers numbers
such as z or i*/

/*complex number z = */

/*complex number i = */

typedef struct window_size_s
{
	int32_t width;
	int32_t height;
}	window_size_t;

typedef struct flags_s
{
	bool	maximize;
	bool	invert;
	bool	monochrome;
	bool	terminal;
}			flags_t;

typedef struct s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_t			*win;
	double			zoom;
	double			x;
	double			y;
	fractal_type_t	type;
	uint32_t		color;
	flags_t			flag;
	window_size_t	w_size;
}					fractal_t;

void	start_mlx(fractal_t *f);
void	cleanup(fractal_t *f);

//  parse attempt
void	user_input(int ac, char **av, fractal_t *f);
void	entry_guide();

// init bools as false
void	init_flag_bools(fractal_t *f);
void	init_fractal_bools(fractal_t *f);

// the rendering
void	render(fractal_t *f);
void	init_fractal(fractal_t *f);

// the fractal
void	draw_mandelbrot(fractal_t *f);
void	draw_burning_ship(fractal_t *f);
void	draw_fern(fractal_t *f);
void	draw_sierpinsky(fractal_t *f);

// mlx controls function
void	ft_hook(mlx_key_data_t key_data, void *param);
void	ft_scrollhook(double xdelta, double ydelta, void *param);

#endif