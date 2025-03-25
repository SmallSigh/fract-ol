#ifndef MAIN_HEADER_H
 #define MAIN_HEADER_H

 #include "../lib/gnl/get_next_line.h"
 #include "../lib/libft/libft.h"
 #include "../lib/ft_printf/ft_printf.h"
 #include "MLX42/MLX42.h"

 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>

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

#define FLAG_MAXIMIZE		"-m"
#define FLAG_BLACK_WHITE	"-b"
#define FLAG_INVERT			"-c"

// typedef struct user_input_s
// {
// 	int		ac;
// 	char	**av;
// 	flags_t	flag;
// }			user_input_t;

typedef struct flags_s
{
	bool	maximize;
	bool	invert;
	bool	monochrome;
}			flags_t;

// mandelbrot struct

// r = real number z
// i = imaginary number z
// tranlate number to coordinates
// cr = coordinates real
// ci = coordiantes imaginary

// i = iterations
// mi = max iterations
// zoom
// x = offsetX
// y = offsetY

typedef struct mandelbrot_s
{
	double	r;
	double	i;
	double	cr;
	double	ci;
	int		iter;
	int		mi;
	double	zoom;
	double	x;
	double	y;
}		mandelbrot_t;

 void	start_mlx(mlx_t **mlx, flags_t *flag);
 void	ft_hook(mlx_key_data_t key_data, void *param);
 void	cleanup(mlx_t *mlx, flags_t *flag);

//  parse attempt
void	user_input(int ac, char **av, flags_t *flag);
void	entry_guide(flags_t *flag);

// flags for fanciness
void    flags_init(flags_t *flag);

#endif