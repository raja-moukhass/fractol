#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include <stdio.h>

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>

# define WIDTH 700
# define HEIGHT 700

typedef struct s_image
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}				t_image;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_image	image;
}				t_mlx;

typedef struct s_frac
{
	t_mlx	mlx;
	int		type;
}				t_frac;

#endif
// mandelbrot julia burningship
// type :
// mandelbrot = 1
// julia = 2
// burningship = 3

// for (int row = 0; row < height; row++) {
//             for (int col = 0; col < width; col++) {
//                 double c_re = (col - width/2)*4.0/width;
//                 double c_im = (row - height/2)*4.0/width;
//                 double x = 0, y = 0;
//                 int iterations = 0;
//                 while (x*x+y*y < 4 && iterations < max) {
//                     double x_new = x*x-y*y+c_re;
//                     y = 2*x*y+c_im;
//                     x = x_new;
//                     iterations++;
//                 }
//                 if (iterations < max) image.setRGB(col, row, white);
//                 else image.setRGB(col, row, black);
//             }
//         }
                                                                                                                                                                                                                                                                                                                              mnm
