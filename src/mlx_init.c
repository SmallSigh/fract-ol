#include "main_header.h"

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	mlx_t *mlx;

	mlx = param;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(mlx);
		if (key_data.key == MLX_KEY_UP)
			ft_printf("up key has been pressed\n");
		if (key_data.key == MLX_KEY_DOWN)
			ft_printf("down key has been pressed\n");
	}
}

void	maximize_window(mlx_t *mlx)
{
	int32_t width;
	int32_t height;

	mlx_get_monitor_size(0, &width, &height);
	mlx_set_window_size(mlx, width, height);
}

void	start_mlx(mlx_t **mlx, flags_t *flag)
{
	*mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", true);
	if (flag->maximize == true)
		maximize_window(*mlx);
	mlx_key_hook(*mlx, ft_hook, *mlx);
	mlx_loop(*mlx);
}

void	cleanup(mlx_t *mlx, flags_t *flag)
{
	free(flag);
	if (mlx != NULL)
		mlx_terminate(mlx);
}
