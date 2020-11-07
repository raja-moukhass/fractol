 #ifndef FRACTOL_H
 # define FRACTOL_H
 # include "../libft/libft.h"
 # include "../miniLibX/mlx.h"
 # include <pthread.h>
 # include <fcntl.h>
 # include <math.h>
 # include <stdlib.h>
 # define WIDTH 1700
 # define HEIGHT 1700



typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;

}				t_mlx;


typedef struct s_draw
{
	int row;
	int height;
	int width;
	
	double c_re;
	double c_im;
	double x;
	double y;
	int iterations;
	double x_new;
	int col;
	int max;
} t_draw;

typedef struct s_frac
{
	t_mlx	mlx;
	int		type;
	int key;
	int key2;
	int test;
	t_draw draw;
	

}				t_frac;


void	draw_mandelbrot(t_frac *f);
void	draw_burningship(t_frac *f);
void	check_av(char *str, int *type);
void	ft_draw(t_frac *f);


#endif


// static int      ft_move(int keycode, t_mlx *mlx)
// {
//         double  c;
//         c = ((MAXX - MINX) / WIN_W) * 10;
//         if (keycode == 123)
//         {
//                 MINX += c;
//                 MAXX += c;
//         }
//         else if (keycode == 124)
//         {
//                 MINX -= c;
//                 MAXX -= c;
//         }
//         else if (keycode == 125)
//         {
//                 MINY -= c;
//                 MAXY -= c;
//         }
//         else if (keycode == 126)
//         {
//                 MINY += c;
//                 MAXY += c;
//         }
//         return (0);
// }
// static int      ft_julia(t_mlx *mlx, int x, int y)
//  {
//          t_f             *f;
//          int             i;
//          double  tmp;
//          f = mlx->f;
//          i = -1;
//          f->pr = MINX + ((double)x * (MAXX - MINX) / WIN_W);
//          f->pi = MINY + ((double)y * (MAXY - MINY) / WIN_H);
//          while (++i < mlx->iter && (f->pr * f->pr + f->pi * f->pi) < 4)
//          {
//                  tmp = f->pr;
//                  f->pr = f->pr * f->pr - f->pi * f->pi + f->cr;
//                  f->pi = 2 * f->pi * tmp + f->ci;
//          }
//          return (i);
//  
