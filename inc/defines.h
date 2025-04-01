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

#ifndef DEFINES_H
# define DEFINES_H

# define INSTRUCTIONS "\n\n\
 \
Usage: ./fractal [(fractal 1-4)] [flags]\n\n\
Fractals:\n\
	\t1. Mandelbrot\n\
	\t2. Burning Ship\n\
	\t3. Julia-set\n\n\
Flags:\n\
	\t-m for monochrome\n\
	\t-i for inverted colours\n\
	\t-f for fullscreen window\n\
		\t\t(removes cross to close...)\n\n\
hint, use the arrow keys on julia...\n"

# define FLAG_MAXIMIZE		"-f"
# define FLAG_BLACK_WHITE	"-m"
# define FLAG_INVERT		"-i"
# define FLAG_TERMINAL		"-t"

# define BLACK		0x000000FF
# define WHITE		0xFAFAFAFF
# define RED		0xFF0000FF
# define GREEN		0x00FF00FF
# define BLUE		0x0000FFFF
# define YELLOW		0xFFFF00FF
# define CYAN		0x00FFFF00
# define MAGENTA	0xFF00FFFF
# define ORANGE		0xFFA500FF
# define PURPLE		0x800080FF

# define GREY_1		0xFAFAFAFF
# define GREY_2		0xF0F0F0FF
# define GREY_3		0xE0E0E0FF
# define GREY_4		0xD0D0D0FF
# define GREY_5		0xC0C0C0FF
# define GREY_6		0xA0A0A0FF
# define GREY_7		0x808080FF
# define GREY_8		0x606060FF
# define GREY_9		0x404040FF
# define GREY_10	0x202020FF

# define WIDTH 1080
# define HEIGHT 1080
# define MAX_ITERATIONS 100
# define FERN_ITERATIONS 100000

// # define DEBUG ft_printf("%s, %d"__FILE__, __LINE__)
#endif