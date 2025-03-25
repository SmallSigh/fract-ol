#include "main_header.h"

void	print_entry_error(flags_t *flag)
{
	free(flag);
	ft_printf("Inputs are considered invalid, please try contacting support\n");
	ft_printf(INSTRUCTIONS);
	exit(1);
}

void	choose_fractal(char *user_input, flags_t *flag)
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
		print_entry_error(flag);
}

void	parse_flags(int ac, char **av, flags_t *flag)
{
	int i;

	i = 2;
	while (i < ac)
	{
		if (!ft_strncmp(av[i], FLAG_MAXIMIZE, 4))
			flag->maximize = true;
		else if (!ft_strncmp(av[i], FLAG_INVERT, 4))
			flag->invert = true;
		else if (!ft_strncmp(av[i], FLAG_BLACK_WHITE, 4))
			flag->monochrome = true;
		else
        {
			print_entry_error(flag);
        }
		i++;
	}
}

void	parse_input(char **av, flags_t *flag)
{
	int user_input = ft_atoi(av[1]);
	if (user_input >= 1 || user_input <= 4)
		choose_fractal(av[1], flag);
	else
		print_entry_error(flag);
}

void	user_input(int ac, char **av, flags_t *flag)
{
	flags_init(flag);
	if (ac == 1)
		entry_guide(flag);
	if (ac == 2)
		parse_input(av, flag);
	if (ac >=3 && ac <= 5)
		parse_flags(ac, av, flag);
	if (ac > 5)
		print_entry_error(flag);
}
