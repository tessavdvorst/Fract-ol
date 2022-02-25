/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:18:27 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/25 11:46:10 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int key_hook(int keycode, t_fractal *fractal)
{
	printf("%d\n", keycode);
	if (keycode == KEY_LEFT)
	{		
		fractal->offset_r -= 0.1;
        make_fractal(fractal);
	}
	if (keycode == KEY_RIGHT)
	{		
		fractal->offset_r += 0.1;
        make_fractal(fractal);
	}
	if (keycode == KEY_UP)
	{		
		fractal->offset_i -= 0.1;
        make_fractal(fractal);
	}
	if (keycode == KEY_DOWN)
	{		
		fractal->offset_i += 0.1;
        make_fractal(fractal);
	}
	if (keycode == SPACE)
	{
		printf("before press %d\n", fractal->color);
		if (fractal->color >= 0 && fractal->color < 2)
			fractal->color += 1;
		else
			fractal->color = 0;
		printf("after press %d\n", fractal->color);
		make_fractal(fractal);
	}
	if (keycode == ESC) // if esc is pressed
		ft_close(fractal);
    return (0);
}

int	ft_close(t_fractal *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
	return (0);
}
