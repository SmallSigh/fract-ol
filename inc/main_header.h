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

 #define WIDTH 1080
 #define HEIGHT 1080
 #define MAX_ITERATIONS 1000

 #define INSTRUCTIONS "\n\n\
 \
Usage: ./fractal [(fractal 1-3)] [flags]\n\n\
Fractals:\n\
	\t1. Mandelbrot\n\
	\t2. Burning Ship\n\
	\t3. Sierpinski/Zelda\n\
	\t4. Barnsley Fern\n\n\
Flags:\n\
	\t-m for maximized window\n\
	\t-b for black and white colours\n\
	\t-c for inverted colours\n\n"

typedef enum e_fractal_type
{
	MANDELBROT,
	BURNING_SHIP,
	SIERPINSKY,
	BARNSLEY_FERN
}	fractal_t_type;

#define FLAG_MAXIMIZE		"-m"
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
	double			zoom;
	double			x;
	double			y;
	int				max_iter;
	fractal_t_type	type;
	uint32_t		color;
	flags_t			flag;
}					fractal_t;


 void	start_mlx(fractal_t *f);
 void	ft_hook(mlx_key_data_t key_data, void *param);
 void	cleanup(fractal_t *f);

//  parse attempt
void	user_input(int ac, char **av, fractal_t *f);
void	entry_guide();

// flags for fanciness
void	flags_init(fractal_t *f);

// the rendering
void	render(fractal_t *f);
void	init_fractal(fractal_t *f, int type);

// the fractal
void	draw_mandelbrot(fractal_t *f);

#endif