/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 11:13:31 by Tessa         #+#    #+#                 */
/*   Updated: 2023/05/22 21:31:37 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	window_init(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGTH, "Fract-ol");
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGTH);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->move_x = 0;
	fractal->move_y = 0;
	fractal->zoom = 1;
	if (fractal->name == 's')
	{
		fractal->offset_r = -2.4;
		fractal->offset_i = -2.0;
	}
	else
	{
		if (fractal->name == 'm')
			fractal->offset_r = -2.5;
		else
			fractal->offset_r = -2.0;
		fractal->offset_i = -1.5;
	}
}

void	color_pixel(t_fractal *fractal, int x, int y)
{
	int			iter;
	t_complex	complex;

	iter = 0;
	complex.re = ((double)x * ((4.0 / WIDTH) * fractal->zoom)
			+ fractal->offset_r * fractal->zoom) + fractal->move_x;
	complex.im = ((double)y * ((3.0 / HEIGTH) * fractal->zoom)
			+ fractal->offset_i * fractal->zoom) + fractal->move_y;
	if (fractal->name == 'm')
		iter = mandelbrot(complex);
	else if (fractal->name == 'j')
		iter = julia(fractal, complex);
	else if (fractal->name == 's')
		iter = ship(complex);
	if (iter != MAX_ITERATIONS)
		my_mlx_pixel_put(fractal, x, y, color(fractal, iter));
	else
		my_mlx_pixel_put(fractal, x, y, BLACK);
}

void	draw_fractal(t_fractal *fractal)
{
	int			x;
	int			y;

	y = 0;
	while (y < HEIGTH)
	{
		x = 0;
		while (x < WIDTH)
		{
			color_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
