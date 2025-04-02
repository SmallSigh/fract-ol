/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:16:39 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 21:42:52 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	print_entry_error(void)
{
	ft_printf("Inputs are considered invalid, please try contacting support\n");
	ft_printf(INSTRUCTIONS);
	exit(1);
}

void	parse_flags(int ac, char **av, t_fractal *f)
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
		else
			print_entry_error();
		i++;
	}
}

void	parse_input(char **av, t_fractal *f)
{
	int	user_input;

	user_input = ft_atoi(av[1]);
	if (user_input >= 1 && user_input <= 3 && !av[1][1])
		f->fractal_type = user_input;
	else
		print_entry_error();
}

void	user_input(int ac, char **av, t_fractal *f)
{
	if (ac == 1)
		entry_guide();
	if (ac >= 2)
		parse_input(av, f);
	if (ac >= 3 && ac <= 5)
		parse_flags(ac, av, f);
	if (ac > 5)
		print_entry_error();
}
