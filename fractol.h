/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 09:26:01 by Tessa         #+#    #+#                 */
/*   Updated: 2022/02/15 15:23:54 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

# define WIDTH 1000
# define HEIGTH 750
// # define MIN_X -2.0
// # define MAX_X 2.0
// # define MIN_Y -1.5
// # define MAX_Y 1.5
// # define OFFSET_X -2.0
// # define OFFSET_Y -1.5
//# define ZOOM 1
# define MAX_ITERATIONS 60

# define KEY_UP 126
# define KEY_DOWN 125
# define ESC 53

typedef struct	s_fractal {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*name;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	offset_x;
	double	offset_y;
}				t_fractal;

typedef struct	s_complex {
	double	re;
	double	im;
}				t_complex;

// USE MY OWN PRINTF??

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);
int	color_neon(int n);
int	color_green(int n);
void	make_black_window(t_fractal *fractal);
int 	key_hook(int key_hook, t_fractal *fractal);
int 	close_window(int keycode, t_fractal *fractal);
int 	read_input(t_fractal *fractal, char *str);
void 	make_fractal(t_fractal *fractal);
void 	window_init(t_fractal *fractal);
void 	mandelbrot_init(t_fractal *fractal);
void 	julia_init(t_fractal *fractal);
//void	draw_blank_space(t_fractal img, int sx, int sy);
//void	draw_pink_square_outline(t_fractal img, int sx, int sy);
//void    bres_draw_blue_circle(t_fractal img, int xc, int yc, int r);
//void	draw_rainbow_square(t_fractal img);
//void	draw_line(t_fractal img, int sx, int sy, int length);
//int  	add_shade(double distance, int color);
//void	draw_shade(t_fractal img);
int	create_rgb(int r, int g, int b);
void draw_mandelbrot(t_fractal *fractal);
int mandelbrot(t_complex z, t_complex complex);
void draw_julia(t_fractal *fractal);//, t_fractal fractal);
int julia(t_complex z, t_complex complex);
t_complex add_complex(t_complex x, t_complex y);
t_complex square_complex(t_complex x);
//int		gradient(t_fractal, int startcol, int endcol);

#endif