/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <moraja858@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:35:15 by ramoukha          #+#    #+#             */
/*   Updated: 2020/03/07 15:46:03 by ramoukha         ###   ########.fr       */
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

/*
**
*/

void	draw_mandelbrot(t_frac f)
{
	(void) f;
	ft_putendl("mandel");
}


void	draw(t_frac f)
{
	if (f.type == 1)
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
	f.mlx.mlx_ptr= mlx_init();
	f.mlx.mlx_win = mlx_new_window(f.mlx.mlx_ptr, WIDTH, HEIGHT, av[1]);
	draw(f);
	mlx_loop(f.mlx.mlx_ptr);
}
