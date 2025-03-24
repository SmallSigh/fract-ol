/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:29 by masmit            #+#    #+#             */
/*   Updated: 2025/03/22 18:12:10 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

#define INSTRUCTIONS "Welcome to my fractal render\n\n\
Usage: ./fractal [(fractal 1-3)] [flags]\n\n\
Fractals:\n\
\t1. Mandelbrot\n\t2. Burning Ship\n\
\t3. Sierpinski/Zelda\n\t4. Barnsley Fern\n\n\
Flags:\n\
\t-m for maximized window\n\
\t-b for black and white colours\n\
\t-c for inverted colours\n"

#define FLAG_MAXIMIZE		"-m"
#define FLAG_BLACK_WHITE	"-b"
#define FLAG_INVERT			"-c"

typedef struct flags_s
{
	bool	maximize;
	bool	invert;
	bool	monochrome;
}			flags_t;

void	entry_guide()
{
	ft_printf(INSTRUCTIONS);
	exit(1);
}

void	print_entry_error()
{
	ft_printf("Inputs are considered invalid, please try contacting support\n");
	ft_printf(INSTRUCTIONS);
	exit(1);
}

void	choose_fractal(char *user_input)
{
	if (!ft_strncmp(user_input, "1", 1))
	{
		ft_printf("User has choosen: Mandelbrot\n");

	}
	else if (!ft_strncmp(user_input, "2", 1))
	{
		ft_printf("User has choosen: Burning Ship\n");

	}
	else if (!ft_strncmp(user_input, "3", 1))
	{
		ft_printf("User has choosen: Sierpinski/Zelda\n");

	}
	else if (!ft_strncmp(user_input, "4", 1))
	{
		ft_printf("User has choosen: Barnsley Fern\n");

	}
	else
		print_entry_error();
}

void	parse_flags(int ac, char **av)
{
	int i;
	flags_t *flag;
	flags_init(flag);

	i = 2;
	while (i < ac)
	{
		if (!ft_strncmp(av[i], FLAG_MAXIMIZE, 2))
			flag->maximize = true;
		else if (!ft_strncmp(av[i], FLAG_INVERT, 2))
			flag->invert = true;
		else if (!ft_strncmp(av[i], FLAG_BLACK_WHITE, 2))
			flag->monochrome = true;
		else
			print_entry_error();
		i++;
	}
}

void	parse_input(char **av)
{
	int user_input = ft_atoi(av[1]);
	if (user_input >= 1 || user_input <= 4)
		choose_fractal(av[1]);
	else
		print_entry_error();
}

void	user_input(int ac, char **av)
{
	if (ac == 1)
		entry_guide();
	if (ac == 2)
		parse_input(av);
	if (ac >=3 && ac <= 5)
		parse_flags(ac, av);
	if (ac > 5)
		print_entry_error();
}

int main(int ac, char **av)
{
    mlx_t *mlx;

	mlx = NULL;
	user_input(ac, av);
	start_mlx(&mlx);
    cleanup(mlx);
    return (0);
}
