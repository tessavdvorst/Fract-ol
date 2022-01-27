/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/12 09:26:01 by Tessa         #+#    #+#                 */
/*   Updated: 2022/01/27 15:18:27 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_complex {
	double	re;
	double	im;
}				t_complex;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int closed(int keycode, t_vars *vars);
//void	draw_blank_space(t_data img, int sx, int sy);
//void	draw_pink_square_outline(t_data img, int sx, int sy);
//void    bres_draw_blue_circle(t_data img, int xc, int yc, int r);
//void	draw_rainbow_square(t_data img);
//void	draw_line(t_data img, int sx, int sy, int length);
int  	add_shade(double distance, int color);
void	draw_shade(t_data img);
int	create_rgb(int r, int g, int b);
void plotCplane(t_data img);
int mandelbrot(t_complex z, t_complex complex);
t_complex add_complex(t_complex x, t_complex y);
t_complex square_complex(t_complex x);
//int		gradient(t_data, int startcol, int endcol);

#endif