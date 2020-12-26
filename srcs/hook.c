/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:56:48 by ramoukha          #+#    #+#             */
/*   Updated: 2020/12/22 13:26:54 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_structure(t_mlx *data)
{
	ft_memdel((void **)&(data->mlx));
	ft_memdel((void **)&(data->win));
	ft_memdel((void **)&(data->img));
	ft_memdel((void **)&(data->img_ptr));
	ft_memdel((void **)&(data));
}

int		key_hook(int key, t_mlx *data)
{
	if (key == EXIT)
	{
		free_structure(data);
		exit(1);
	}
	else if (key == ITERATION_PLUS)
		data->it_max += 50;
	else if (key == ITERATION_MINUS)
		data->it_max -= 50;
	else if (key == LEFT)
		data->x1 += 30 / data->zoom;
	else if (key == RIGHT)
		data->x1 -= 30 / data->zoom;
	else if (key == BOTTOM)
		data->y1 -= 30 / data->zoom;
	else if (key == TOP)
		data->y1 += 30 / data->zoom;
	else if (key == SPACE)
		data->julia_mouse = !data->julia_mouse;
	else if (key == C_INSIDE)
		data->color_in += 5;
	else if (key == C_OUTSIDE)
		data->color = 1677;
	fract_calc(data);
	return (0);
}

void	ft_zoom(int x, int y, t_mlx *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom * 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom * 1.3));
	data->zoom *= 1.3;
	data->it_max++;
}

void	ft_dezoom(int x, int y, t_mlx *data)
{
	data->x1 = (x / data->zoom + data->x1) - (x / (data->zoom / 1.3));
	data->y1 = (y / data->zoom + data->y1) - (y / (data->zoom / 1.3));
	data->zoom /= 1.3;
	data->it_max--;
}

int		mouse_hook(int mousecode, int x, int y, t_mlx *data)
{
	if (mousecode == 4 || mousecode == 1)
		ft_zoom(x, y, data);
	else if (mousecode == 5 || mousecode == 2)
		ft_dezoom(x, y, data);
	fract_calc(data);
	return (0);
}
