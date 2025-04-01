#ifndef MAIN_DEFINE_H
# define MAIN_DEFINE_H

# define INSTRUCTIONS "\n\n\
 \
Usage: ./fractal [(fractal 1-4)] [flags]\n\n\
Fractals:\n\
	\t1. Mandelbrot\n\
	\t2. Burning Ship\n\
	\t3. Julia-set\n\
	\t4. Barnsley Fern\n\n\
Flags:\n\
	\t-f for fullscreen window\n\
	\t-b for black and white colours\n\
	\t-c for inverted colours\n\
	\t-t for fractal in terminal, WIP, only for mandelbrot\n"

# define FLAG_MAXIMIZE		"-f"
# define FLAG_BLACK_WHITE	"-b"
# define FLAG_INVERT			"-c"
# define FLAG_TERMINAL		"-t"

# define BLACK		0x000000FF
# define WHITE		0xFFFFFF00
# define RED		0xFF0000FF
# define GREEN		0x00FF00FF
# define BLUE		0x0000FFFF
# define YELLOW		0xFFFF00FF
# define CYAN		0x00FFFF00
# define MAGENTA	0xFF00FFFF
# define ORANGE		0xFFA500FF
# define PURPLE		0x800080FF

//  for monochrome
// grey is in different brigtness, 0xFF for white
// 16 for red to grey
// 8 for green to grey
// nothing for blue to grey

# define SET_MONO(gray)	((0xFF << 24) |\
((gray) << 16) |\
((gray) << 8) |\
(gray))

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITERATIONS 100
# define FERN_ITERATIONS 100000

// # define DEBUG ft_printf("%s, %d"__FILE__, __LINE__)
#endif