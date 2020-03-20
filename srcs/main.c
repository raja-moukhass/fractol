/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:35:15 by ramoukha          #+#    #+#             */
/*   Updated: 2020/03/11 18:07:00 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/fractol.h"

void		show_usage(void)
{
	ft_putendl("⛔️ Usage: ./fractol [set name]⛔️");
	ft_putendl("option : \n1/ mandelbrot\n2/ julia\n3/ burningship");
	exit(0);
}
int		ft_close(void)
{
	
	exit(EXIT_SUCCESS);
	return (1);
}

int	ft_key_perssed(int keycode, t_frac *f)
{

	if ( keycode == 123)
	f->key += 1;
	if ( keycode == 124)
	f->key -= 1;
	if (keycode == 126)
	f->key2 +=1;
	if (keycode == 125)
	f->key2 -=1;

	if (keycode == 53)
		ft_close();
	draw_mandelbrot(f);
	mlx_put_image_to_window(f->mlx.mlx_ptr, f->mlx.mlx_win, f->mlx.img_ptr, 0, 0);
	return(1);
}

void	check_av(char *str, int *type)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		*type = 1;
	else if ( ft_strcmp( str, "julia") == 0)
		*type = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		*type = 3;
	else
		show_usage();
}


void	draw_mandelbrot(t_frac *f) 
{
	t_draw draw;
	draw.max = 50;
	int row;
	row = -1;
	int col = 0;
	//col = -1;

	while( ++row < HEIGHT)
	{
		col = -1;
		while (++col < WIDTH)
		{
			 draw.c_re  = (col - WIDTH/2.0)*4.0/WIDTH + f->key;
			 draw.c_im = (row - HEIGHT/2.0)*4.0/WIDTH + f->key2;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < draw.max) {
				 draw.x_new = x*x - y*y + draw.c_re;
				y = 2*x*y + draw.c_im;
				x  = draw.x_new;
				iteration++;
			}


			if (iteration < draw.max)
				f->mlx.data[row * WIDTH + col] = 15213899 * iteration ;
			else f->mlx.data[row * WIDTH + col] =0;
		}
	}
}

void	draw_burningship(t_frac *f)
{
	t_draw draw;
	draw.max = 50;

	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			double c_re = (col - WIDTH/2.0)*4.0/WIDTH;
			double c_im = (row - HEIGHT/2.0)*4.0/WIDTH;
			int iteration = 0;
			while (draw.x*draw.x+draw.y*draw.y <= 4 && iteration < draw.max) {
				double x_new = draw.x*draw.x - draw.y*draw.y + c_re ;
				draw.y = 2*draw.x*draw.y + c_im;
				draw.x = x_new;
				iteration++;
			}
			if (iteration < draw.max)
				f->mlx.data[row * WIDTH + col] = 515112 * iteration;
			else f->mlx.data[row * WIDTH + col] = 0;
		}
	}
}






void	ft_draw(t_frac *f)
{
	if (f->type == 1)
		draw_mandelbrot(f);
	// if (f->type == 2)
	// 	draw_julia(f);
	if (f->type == 3)
		draw_burningship(f);
}


int		main(int ac, char **av)
{
	t_frac	f;
	//\t_draw draw;
	f.key = 0;
	f.key2 = 0;
	if (ac == 2)
		check_av(av[1], &(f.type));
	else
		show_usage();
	f.mlx.mlx_ptr = mlx_init();
	f.mlx.mlx_win = mlx_new_window(f.mlx.mlx_ptr, WIDTH, HEIGHT, av[1]);
	f.mlx.img_ptr = mlx_new_image(f.mlx.mlx_ptr,WIDTH, HEIGHT);
	f.mlx.data = (int*)mlx_get_data_addr( f.mlx.img_ptr,&f.mlx.bpp, &f.mlx.size_l, &f.mlx.endian);
	ft_draw(&f);
	mlx_put_image_to_window(f.mlx.mlx_ptr, f.mlx.mlx_win, f.mlx.img_ptr, 0, 0);
	mlx_hook(f.mlx.mlx_win, 17, 0 ,ft_close, &f);
	mlx_hook( f.mlx.mlx_win, 2, 0,ft_key_perssed,&f);
	
	mlx_loop(f.mlx.mlx_ptr);
}
