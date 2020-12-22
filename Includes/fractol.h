/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoukha <ramoukha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 13:06:46 by ramoukha          #+#    #+#             */
/*   Updated: 2020/12/17 18:59:56 by ramoukha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "mlx.h"
# include "math.h"
# include "pthread.h"
# define WIDTH 600
# define HEIGHT 600
# define THREAD_WIDTH 5
# define THREAD_NUMBER 120
# define EXIT 53
# define ITERATION_PLUS 69
# define ITERATION_MINUS 78
# define LEFT 123
# define RIGHT 124
# define BOTTOM 125
# define TOP 126
# define C_INSIDE 34
# define C_OUTSIDE 8
# define SPACE 49
# define ACTIVED_MOUSE 1

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_ptr;
	int			endian;
	int			sl;
	int			bpp;
	int			fract;
	int			color;
	int			julia_mouse;
	int			x;
	int			y;
	int			y_max;
	int			it;
	int			it_max;
	int			show_text;
	double		zoom;
	double		x1;
	double		y1;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		tmp;
	int			red;
	int			color_in;
	int			stop_keyboard;
}				t_mlx;

void			show_usage(void);
void			all_init(t_mlx *data);

int				key_hook(int keycode, t_mlx *data);
void			all_init(t_mlx *data);

int				key_hook2(int keycode, t_mlx *data);
void			ft_zoom(int x, int y, t_mlx *data);
void			ft_dezoom(int x, int y, t_mlx *data);
int				mouse_hook(int mousecode, int x, int y, t_mlx *data);

void			mandelbrot_math(t_mlx *data);
void			*mandelbrot(void *tab);
void			mandelbrot_pthread(t_mlx *data);
void			put_pixel_image(t_mlx *data);

int				mouse_julia(int x, int y, t_mlx *data);
void			julia_math(t_mlx *data);
void			*julia(void *tab);
void			julia_pthread(t_mlx *data);

void			burningship_math(t_mlx *data);
void			*burningship(void *tab);
void			burningship_pthread(t_mlx *data);

int				ft_close(void);
void			put_pxl_to_img(t_mlx *data, int x, int y, int color);
void			put_text(t_mlx *data);

void			fract_calc(t_mlx *data);
void			fract_init(t_mlx *data);
void			mlx_win_init(t_mlx *data, char *title);
void			fract_comp(char **av, t_mlx *data);

void			tricorn_math(t_mlx *data);
void			*tricorn(void *tab);
void			tricorn_pthread(t_mlx *data);


#endif
