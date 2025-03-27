#include "main_header.h"

static void	zoom_at_position(fractal_t *f, double zoom_factor, int mouse_x, int mouse_y)
{
    double  mouse_r;
    double  mouse_i;
    double  new_center_r;
    double  new_center_i;

    mouse_r = (mouse_x - f->w_size.width / 2.0) * 4.0 / (f->w_size.width * f->zoom) + f->x;
    mouse_i = (mouse_y - f->w_size.height / 2.0) * 4.0 / (f->w_size.height * f->zoom) + f->y;

    new_center_r = f->x + (mouse_r - f->x) * (1 - 1/zoom_factor);
    new_center_i = f->y + (mouse_i - f->y) * (1 - 1/zoom_factor);

    f->x = new_center_r;
    f->y = new_center_i;
    f->zoom *= zoom_factor;
}

int	valid_mouse_pos(int mouse_x, int mouse_y, fractal_t *f)
{
	if (mouse_x > f->w_size.width || mouse_x < 0)
		return (1);
	if (mouse_y > f->w_size.height || mouse_x < 0)
		return (1);
	return (0);
}

void	ft_scrollhook(double xdelta, double ydelta, void *param)
{
    fractal_t	*f;
    int			mouse_x;
    int			mouse_y;
    double		zoom_factor;

    (void)xdelta;
    f = (fractal_t *)param;
    mlx_get_mouse_pos(f->mlx, &mouse_x, &mouse_y);
	if (valid_mouse_pos(mouse_x, mouse_y, f))
		return;
    if (ydelta > 0)
        zoom_factor = 1.1;
    else
        zoom_factor = 0.9;
    zoom_at_position(f, zoom_factor, mouse_x, mouse_y);
    render(f);
}

void	ft_hook(mlx_key_data_t key_data, void *param)
{
	fractal_t *f;

	f = param;
	if (key_data.action == MLX_PRESS)
	{
		if (key_data.key == MLX_KEY_ESCAPE)
			mlx_close_window(f->mlx);
		if (key_data.key == MLX_KEY_UP)
			ft_printf("up key has been pressed\n");
		if (key_data.key == MLX_KEY_DOWN)
			ft_printf("down key has been pressed\n");
	}
}
