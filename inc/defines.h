/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:05 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 23:07:20 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define INSTRUCTIONS "\n\n\
 \
Usage: ./fractol [(fractal 1-3)] [flags]\n\n\
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

# define BLACK				0xFF000000
# define WHITE				0xFFFAFAFA

# define BLUE_1				0xFFE6001A
# define BLUE_2				0xFFCC0033
# define BLUE_PURPLE		0xFFB3004D
# define PURPLE_BLUE		0xFF990066
# define PURPLE_1			0xFFCC3299
# define PURPLE_2			0xFF800080
# define PURPLE_3			0xFF660099
# define PURPLE_4			0xFF4D00B3

# define GREY_1				0xFFFAFAFA
# define GREY_2				0xFFF0F0F0
# define GREY_3				0xFFE0E0E0
# define GREY_4				0xFFD0D0D0
# define GREY_5				0xFFC0C0C0
# define GREY_6				0xFFA0A0A0
# define GREY_7				0xFF808080
# define GREY_8				0xFF606060
# define GREY_9				0xFF404040
# define GREY_10			0xFF202020

# define WIDTH				1080
# define HEIGHT				1080
# define MAX_ITERATIONS		20
# define BPP				sizeof(int32_t)

#endif