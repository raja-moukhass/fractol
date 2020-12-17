
#include "../Includes/fractol.h"

void		all_init(t_mlx *data)
{
	data->it_max = 50;
    data-> red = (SQR(data->color_in) * 30) % 255;
	data->zoom = 200;
	data->x1 = -2.0;
	data->y1 = -1.9;
	data->color = 265;
	data->c_r = 0.285;
	data->c_i = 0.01;
    data->color_in = 0;
	data->julia_mouse = 1;
}
void	mandelbrot_math(t_mlx *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i *
			data->z_i < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i + data->c_r;
		data->z_i = 2 * data->z_i * data->tmp + data->c_i;
		data->it++;
	}
    put_pixel_image(data);
	
}
void	julia_math(t_mlx *data)
{
	data->z_r = data->x / data->zoom + data->x1;
	data->z_i = data->y / data->zoom + data->y1;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i
			* data->z_i < 4 && data->it < data->it_max)
	{
		data->tmp = data->z_r;
		data->z_r = data->z_r * data->z_r -
			data->z_i * data->z_i - 0.8 + (data->c_r / WIDTH);
		data->z_i = 2 * data->z_i * data->tmp + data->c_i / WIDTH;
		data->it++;
	}
        put_pixel_image(data);

	
}
void			burningship_math(t_mlx *data)
{
	data->c_r = data->x / data->zoom + data->x1;
	data->c_i = data->y / data->zoom + data->y1;
	data->z_r = 0;
	data->z_i = 0;
	data->it = 0;
	while (data->z_r * data->z_r + data->z_i * data->z_i < 4
			&& data->it < data->it_max)
	{
		data->tmp = pow(data->z_r, 2) - pow(data->z_i, 2) + data->c_r;
		data->z_i = fabs(2 * data->z_r * data->z_i) + data->c_i;
		data->z_r = data->tmp;
		data->it++;
	}
    put_pixel_image(data);
	
}
void    put_pixel_image(t_mlx *data)
{
    if (data->it == data->it_max)
		put_pxl_to_img(data, data->x, data->y, data->color_in);
	else
		put_pxl_to_img(data, data->x, data->y, (data->color * data->it));
}
