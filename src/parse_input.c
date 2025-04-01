/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:39 by masmit            #+#    #+#             */
/*   Updated: 2025/03/31 16:02:37 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	print_entry_error(void)
{
	ft_printf("Inputs are considered invalid, please try contacting support\n");
	ft_printf(INSTRUCTIONS);
	exit(1);
}

void	choose_fractal(char *user_input, fractal_t *f)
{
	init_fractal_bools(f);
	if (!ft_strncmp(user_input, "1", 1))
	{
		ft_printf("User has choosen: Mandelbrot\n");
		f->type.MANDELBROT = true;
	}
	else if (!ft_strncmp(user_input, "2", 1))
	{
		ft_printf("User has choosen: Burning Ship\n");
		f->type.BURNING_SHIP = true;
	}
	else if (!ft_strncmp(user_input, "3", 1))
	{
		ft_printf("User has choosen: Julia-Set\n");
		f->type.JULIA = true;
	}
	else if (!ft_strncmp(user_input, "4", 1))
	{
		ft_printf("User has choosen: Barnsley Fern\n");
		f->type.BARNSLEY_FERN = true;
	}
	else
		print_entry_error();
}

// i to 2
// 0 is ./fractal
// 1 is fractal choice
void	parse_flags(int ac, char **av, fractal_t *f)
{
	int	i;

	i = 2;
	while (i < ac)
	{
		if (!ft_strncmp(av[i], FLAG_MAXIMIZE, 4)
			&& f->flag.maximize == false)
			f->flag.maximize = true;
		else if (!ft_strncmp(av[i], FLAG_INVERT, 4)
			&& f->flag.invert == false)
			f->flag.invert = true;
		else if (!ft_strncmp(av[i], FLAG_BLACK_WHITE, 4)
			&& f->flag.monochrome == false)
			f->flag.monochrome = true;
		else if (!ft_strncmp(av[i], FLAG_TERMINAL, 4)
			&& f->flag.terminal == false)
			f->flag.terminal = true;
		else
			print_entry_error();
		i++;
	}
}

void	parse_input(char **av, fractal_t *f)
{
	int	user_input;

	user_input = ft_atoi(av[1]);
	if (user_input >= 1 && user_input <= 4 && !av[1][1])
		choose_fractal(av[1], f);
	else
		print_entry_error();
}

void	user_input(int ac, char **av, fractal_t *f)
{
	if (ac == 1)
		entry_guide(f);
	if (ac >= 2)
		parse_input(av, f);
	if (ac >= 3 && ac <= 5)
		parse_flags(ac, av, f);
	if (ac > 5)
		print_entry_error();
}
