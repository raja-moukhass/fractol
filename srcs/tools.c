/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:00:01 by ramoukha          #+#    #+#             */
/*   Updated: 2020/12/17 18:37:15 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int			ft_close(void)
{
	exit(1);
	return (0);
}

void		put_pxl_to_img(t_mlx *data, int x, int y, int color)
{
	if (data->x < WIDTH && data->y < WIDTH)
	{
		color = mlx_get_color_value(data->mlx, color);
		ft_memcpy(data->img_ptr + 4 * WIDTH * y + x * 4,
				&color, sizeof(int));
	}
}

void		show_usage(void)
{
	ft_putendl("⛔️Usage: ./fractol [set name]");
	ft_putendl("List of available parameters:");
	ft_putendl("1/ mandelbrot\n2/ julia\n3/ burningship\n4/ tricorn");
	exit(0);
}
