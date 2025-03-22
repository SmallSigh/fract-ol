#ifndef MAIN_HEADER_H
 #define MAIN_HEADER_H

 #include "../lib/gnl/get_next_line.h"
 #include "../lib/libft/libft.h"
 #include "../lib/ft_printf/ft_printf.h"
 #include "MLX42/MLX42.h"

 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 #define WIDTH 1080
 #define HEIGHT 1080

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

 typedef struct s_fractol
 {
	double		zoom;
	double		offsetX;
	double		offsetY;
	int			x;
	int			y;
	mlx_image_t	*img;
 }				t_fractol;

#endif