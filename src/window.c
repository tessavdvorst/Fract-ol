/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 11:13:31 by Tessa         #+#    #+#                 */
/*   Updated: 2022/02/25 12:21:20 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void window_init(t_fractal *fractal)
{
		fractal->mlx = mlx_init();
		fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGTH, "Fract-ol");
		fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGTH);
		fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel, &fractal->line_length,
			&fractal->endian);
		fractal->zoom = 1;
		if (ft_ccmp(fractal->name, 'm') == 0)
			mandelbrot_init(fractal);
		else if (ft_ccmp(fractal->name, 'j') == 0)
			julia_init(fractal);
		else if (ft_ccmp(fractal->name, 's') == 0)
			ship_init(fractal);
		else
			printf("Insert valid fractal\n");
		make_fractal(fractal);
}

void make_fractal(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx, fractal->win);
	if (ft_ccmp(fractal->name, 'm') == 0)
		draw_mandelbrot(fractal);
	if (ft_ccmp(fractal->name, 'j') == 0)
		draw_julia(fractal);
	if (ft_ccmp(fractal->name, 's') == 0)
			draw_ship(fractal);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
}
	
	
	
	
	
	//color = add_shade(0.5, color);
	//printf("after adding shade the color will be: %X\n", color);	
	//draw_pink_square_outline(img, 500, 375);
	//draw_blank_space(img, 85, 225);
	//bres_draw_blue_circle(img, 750, 175, 50);
	//draw_rainbow_square(img);
	//draw_shade(img);
	//draw_line(img, 125, 350, 200);