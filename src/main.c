/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:29 by masmit            #+#    #+#             */
/*   Updated: 2025/03/26 17:30:33 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	entry_guide()
{
	ft_printf(INSTRUCTIONS);
	exit(1);
}

void	flags_init(fractal_t *f)
{
	f->flag.invert = false;
	f->flag.maximize = false;
	f->flag.monochrome = false;
	f->flag.terminal = false;
}

int	main(int ac, char **av)
{
	fractal_t	f;

	init_fractal(&f, 0);
	user_input(ac, av, &f);
	// render(&f);
	start_mlx(&f);
	cleanup(&f);
	return (0);
}
