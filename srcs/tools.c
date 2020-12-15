

#include "../Includes/fractol.h"
void	all_init(t_fractol *data)
{
	data->it_max = 50;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 265;
	data->c_r = 0.285;
	data->c_i = 0.01;
	data->julia_mouse = 1;
}
int		ft_close(void)
{
	exit(1);
	return (0);
}

void	put_pxl_to_img(t_fractol *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

