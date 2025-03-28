/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:29 by masmit            #+#    #+#             */
/*   Updated: 2025/03/27 14:30:47 by masmit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_header.h"

void	entry_guide(void)
{
	ft_printf(INSTRUCTIONS);
	exit(1);
}

int	main(int ac, char **av)
{
	fractal_t	f;

	init_flag_bools(&f);
	init_fractal_bools(&f);
	user_input(ac, av, &f);
	start_mlx(&f);
	render(&f);
	mlx_loop(f.mlx);
	cleanup(&f);
	return (0);
}
