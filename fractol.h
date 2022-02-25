/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 09:26:01 by Tessa         #+#    #+#                 */
/*   Updated: 2022/02/25 12:21:30 by tvan-der      ########   odam.nl         */
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
# define MAX_ITERATIONS 200
# define BLACK 0x00000000
# define WHITE 0x00FFFFFF
# define CONST_RE -0.4
# define CONST_IM 0.6

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define SPACE 49
# define ESC 53
# define WHEEL_UP 5
# define WHEEL_DOWN 4

typedef struct	s_fractal {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	name;
	int		color;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		maxint;
 	double	zoom;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	offset_r;
	double	offset_i;
	double	julia_r;
	double	julia_i;
}				t_fractal;

typedef struct	s_complex {
	double	re;
	double	im;
}				t_complex;

// Read input

int 		info_init(t_fractal *fractal, char **str, int argc);
int 		read_fractal(t_fractal *fractal, char *str);
int 		read_c(t_fractal *fractal, char *str, char c);
void 		read_color(t_fractal *fractal, char *str);
void 		print_error(void);

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
double 		julia(t_complex z, t_complex complex);

// Burning ship

int ship(t_complex z, t_complex complex);
void draw_ship(t_fractal *fractal);
void ship_init(t_fractal *fractal);

// Complex number

t_complex 	add_complex(t_complex x, t_complex y);
t_complex 	square_complex(t_complex x);
double		absolute_complex(t_complex complex);
t_complex 	get_abs(t_complex x);

// Key & mouse hooks

int 		key_hook(int key_hook, t_fractal *fractal);
int 		mouse_hook(int mousecode, int x, int y, t_fractal *fractal);
int			ft_close(t_fractal *fractal);

// Color

int 	color(t_fractal *fractal, int n);
int			create_rgb(int r, int g, int b);


#endif