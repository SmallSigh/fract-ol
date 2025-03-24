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

void    start_mlx(mlx_t **mlx)
{
    *mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
    mlx_key_hook(*mlx, ft_hook, *mlx);
    mlx_loop(*mlx);
}

void	cleanup(mlx_t *mlx)
{
	if (mlx != NULL)
		mlx_terminate(mlx);
}
