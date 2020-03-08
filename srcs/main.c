/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <moraja858@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:35:15 by ramoukha          #+#    #+#             */
/*   Updated: 2020/03/08 14:44:59 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		show_usage(void)
{
	ft_putendl("⛔️ Usage: ./fractol [set name]⛔️");
	ft_putendl("option : \n1/ mandelbrot\n2/ julia\n3/ burningship");
	exit(0);
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

	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			double c_re = (col - WIDTH/2.0)*4.0/WIDTH;
			double c_im = (row - HEIGHT/2.0)*4.0/WIDTH;
			double x = 0, y = 0;
			int iteration = 0;
			while (x*x+y*y <= 4 && iteration < draw.max) {
				double x_new = x*x - y*y + c_re;
				y = 2*x*y + c_im;
				x = x_new;
				iteration++;
			}
			if (iteration < draw.max)
				f->mlx.data[row * WIDTH + col] = iteration * 51151;
			else f->mlx.data[row * WIDTH + col] = 0;
		}
	}
}


void	draw(t_frac *f)
{
	if (f->type == 1)
		draw_mandelbrot(f);
	// if (f.type == 2)
	// 	draw_julia(f);
	// if (f.type == 3)
	// 	draw_burningship(f);
}


int		main(int ac, char **av)
{
	t_frac	f;

	if (ac == 2)
		check_av(av[1], &(f.type));
	else
		show_usage();
	f.mlx.mlx_ptr = mlx_init();
	f.mlx.mlx_win = mlx_new_window(f.mlx.mlx_ptr, WIDTH, HEIGHT, av[1]);
	f.mlx.img_ptr = mlx_new_image(f.mlx.mlx_ptr,WIDTH, HEIGHT);
	f.mlx.data = (int*)mlx_get_data_addr( f.mlx.img_ptr,&f.mlx.bpp, &f.mlx.size_l, &f.mlx.endian);
	draw(&f);
	mlx_put_image_to_window(f.mlx.mlx_ptr, f.mlx.mlx_win, f.mlx.img_ptr, 0, 0);
	mlx_loop(f.mlx.mlx_ptr);
}
