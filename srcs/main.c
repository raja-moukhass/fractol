/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:54:06 by ramoukha          #+#    #+#             */
/*   Updated: 2020/12/15 12:54:20 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"
#include <stdio.h>
void		fract_calc(t_fractol *data)
{
	if (data->fract == 0)
		mandelbrot_pthread(data);
	else if (data->fract == 1)
		julia_pthread(data);
	else if (data->fract == 2)
		burningship_pthread(data);
}

void		fract_init(t_fractol *data)
{
	if (data->fract == 0)
		all_init(data);
	else if (data->fract == 1)
		all_init(data);
	else if (data->fract == 2)
		all_init(data);
	fract_calc(data);
}

void		mlx_win_init(t_fractol *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, WIDTH, "Fractol");
	data->img = mlx_new_image(data->mlx, WIDTH, WIDTH);
	data->img_ptr = mlx_get_data_addr(data->img,
			&data->bpp, &data->sl, &data->endian);
	
}

void		fract_comp(char **av, t_fractol *data)
{
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fract = 0;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fract = 1;
	else if (ft_strcmp(av[1], "burningship") == 0)
		data->fract = 2;
	else if ((ft_strcmp(av[1], "burningship") != 0) ||
	(ft_strcmp(av[1], "julia") != 0) || (ft_strcmp(av[1], "mandelbrot") != 0))
	{
		ft_putendl("⛔️name incorrect⛔️");
		exit(0);
	}
}

int			main(int ac, char **av)
{
	t_fractol	*data;

	if (!(data = (t_fractol *)malloc(sizeof(t_fractol))))
		return (-1);
	if (ac == 2)
	{
		fract_comp(av, data);
		mlx_win_init(data);
		fract_init(data);
		mlx_hook(data->win, 6, 1L < 6, mouse_julia, data);
		mlx_hook(data->win, 17, 0L, ft_close, data);
		mlx_key_hook(data->win, key_hook, data);
		mlx_mouse_hook(data->win, mouse_hook, data);
		mlx_loop(data->mlx);
	}
	else
		show_usage();
	return (0);
}
