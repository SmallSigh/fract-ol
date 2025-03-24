#include "main_header.h"

void	structs_init(mandelbrot_t	*brot)
{
	brot->r = 0;
	brot->i = 0;
	brot->cr = 0;
	brot->ci = 0;
	brot->iter = 0;
	brot->mi = 1000;
	brot->zoom = 1.0;
	brot->x = 0.0;
	brot->y = 0.0;
}
