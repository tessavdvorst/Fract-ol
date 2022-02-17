/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:18:27 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/16 16:49:43 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int key_hook(int keycode, t_fractal *fractal)
{
	printf("Hello from key_code: %d!\n", keycode);
	if (keycode == KEY_LEFT)
	{		
		fractal->offset_x -= 0.1;
        make_fractal(fractal);
	}
	if (keycode == KEY_RIGHT)
	{		
		fractal->offset_x += 0.1;
        make_fractal(fractal);
	}
	if (keycode == KEY_UP)
	{		
		fractal->offset_y -= 0.1;
        make_fractal(fractal);
	}
	if (keycode == KEY_DOWN)
	{		
		fractal->offset_y += 0.1;
        make_fractal(fractal);
	}
	if (keycode == ESC) // if esc is pressed
	{
		ft_close(fractal);
	}
    return (0);
}

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}
