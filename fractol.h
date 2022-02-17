/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 09:26:01 by Tessa         #+#    #+#                 */
/*   Updated: 2022/02/17 15:34:29 by tvan-der      ########   odam.nl         */
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
# define MAX_ITERATIONS 60
# define BLACK 0x00000000

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define ESC 53
# define WHEEL_UP 4
# define WHEEL_DOWN 5

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

// Read input

int 		read_input(t_fractal *fractal, char **str, int count);
int 		read_fractal(t_fractal *fractal, char *str);
int 		read_options(t_fractal *fractal);
void 	print_error(void);

// Open window

void 		window_init(t_fractal *fractal);
void 		make_fractal(t_fractal *fractal);

// Draw fractal

void		my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color);

// Mandelbrot set

void 		mandelbrot_init(t_fractal *fractal);
void 		draw_mandelbrot(t_fractal *fractal);
int 		mandelbrot(t_complex z, t_complex complex);

// Julia set

void 		julia_init(t_fractal *fractal);
void 		draw_julia(t_fractal *fractal);
int 		julia(t_complex z, t_complex complex);

// Complex number

t_complex 	add_complex(t_complex x, t_complex y);
t_complex 	square_complex(t_complex x);

// Key & mouse hooks

int 		key_hook(int key_hook, t_fractal *fractal);
int 		mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int		ft_close(t_fractal *fractal);

// Color

int			color_neon(int n);
int			color_pastel(int n);
int			create_rgb(int r, int g, int b);
//void		make_black_window(t_fractal *fractal);




#endif