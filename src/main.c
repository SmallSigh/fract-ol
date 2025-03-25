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

void	entry_guide(flags_t *flag)
{
	free(flag);
	ft_printf(INSTRUCTIONS);
	exit(1);
}

int main(int ac, char **av)
{
    mlx_t *mlx;
	flags_t *flag;

	mlx = NULL;
	flag = malloc(sizeof(flag));
	if (!flag)
		exit(1);
	user_input(ac, av, flag);
	start_mlx(&mlx, flag);
    cleanup(mlx, flag);
    return (0);
}
