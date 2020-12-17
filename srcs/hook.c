/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:56:48 by ramoukha          #+#    #+#             */
/*   Updated: 2020/12/15 12:56:49 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

// int		key_hook2(int keycode, t_mlx *data)
// {
// 	if (keycode == 19)
// 		data->color = 2050;
// 	else if (keycode == 20)
// 		data->color = 265;
	
// 	return (0);
// }

int		key_hook(int keycode, t_mlx *data)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 69) // iteration +
		data->it_max += 50;
	else if (keycode == 78) // iteration -
		data->it_max -= 50;
	else if (keycode == 123) // mouvement to the left
		data->x1 += 30 / data->zoom;
	else if (keycode == 124) // mouvement to the rt
		data->x1 -= 30 / data->zoom; 
	else if (keycode == 125)// bottom mouvement  
		data->y1 -= 30 / data->zoom;
	else if (keycode == 126) // top mouvement 
		data->y1 += 30 / data->zoom;
	else if (keycode == 35) 
		data->julia_mouse = !data->julia_mouse;
	else if (keycode == 49)
		fract_init(data);
	else if(keycode == 34)// color inside "lettre i"
		data->color_in +=5;
	else if (keycode == 8)// lettre c
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
