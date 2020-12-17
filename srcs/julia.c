/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 12:57:59 by ramoukha          #+#    #+#             */
/*   Updated: 2020/12/17 19:04:50 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fractol.h"

int		mouse_julia(int x, int y, t_mlx *data)
{
	if (data->fract == 1 && data->julia_mouse == 1)
	{
		data->c_r = x * 2;
		data->c_i = y * 2 - 800;
		fract_calc(data);
	}
	return (0);
}

void	*julia(void *tab)
{
	int		tmp;
	t_mlx	*data;

	data = (t_mlx *)tab;
	data->x = 0;
	tmp = data->y;
	while (data->x < WIDTH)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			julia_math(data);
			data->y++;
		}
		data->x++;
	}
	return (tab);
}

void	julia_pthread(t_mlx *data)
{
	int			i;
	t_mlx		tab[THREAD_NUMBER];
	pthread_t	t[THREAD_NUMBER];

	i = 0;
	while (i < THREAD_NUMBER)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_mlx));
		tab[i].y = THREAD_WIDTH * i;
		tab[i].y_max = THREAD_WIDTH * (i + 1);
		pthread_create(&t[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
