/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masmit <masmit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:49:29 by masmit            #+#    #+#             */
/*   Updated: 2025/04/02 22:34:28 by masmit           ###   ########.fr       */
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
	t_fractal	f;

	ft_memset(&f, 0, sizeof(t_fractal));
	user_input(ac, av, &f);
	start_mlx(&f);
	render(&f);
	mlx_loop(f.mlx);
	cleanup(&f);
	return (0);
}
