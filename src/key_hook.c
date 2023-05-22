/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:18:27 by tvan-der      #+#    #+#                 */
/*   Updated: 2023/05/22 21:26:54 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	key_hook1(int keycode, t_fractal *fractal)
{
	if (keycode == KEY_LEFT)
	{
		fractal->move_x -= 0.1;
		draw_fractal(fractal);
	}
	else if (keycode == KEY_RIGHT)
	{
		fractal->move_x += 0.1;
		draw_fractal(fractal);
	}
	else if (keycode == KEY_UP)
	{
		fractal->move_y -= 0.1;
		draw_fractal(fractal);
	}
	else if (keycode == KEY_DOWN)
	{
		fractal->move_y += 0.1;
		draw_fractal(fractal);
	}
	else
		key_hook2(keycode, fractal);
	return (0);
}

int	key_hook2(int keycode, t_fractal *fractal)
{
	if (keycode == SPACE)
	{
		if (fractal->color >= 0 && fractal->color < 2)
			fractal->color += 1;
		else
			fractal->color = 0;
		draw_fractal(fractal);
	}
	if (keycode == ESC)
		ft_close(fractal);
	return (0);
}

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}
