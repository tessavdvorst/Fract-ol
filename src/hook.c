/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:18:27 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/10 13:23:21 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int key_hook(int keycode, t_fractal *fractal)
{
	(void)fractal->img;
	printf("Hello from key_code: %d!\n", keycode);
	if (keycode == KEY_UP)
	{		
		fractal->zoom -= 0.1;
		printf("%f\n", fractal->zoom);
        make_fractal(fractal);
	}
	else if (keycode == KEY_DOWN)
	{		
		fractal->zoom += 0.1;
		printf("%f\n", fractal->zoom);
        make_fractal(fractal);
	}
    return (0);
}

int close_window(int keycode, t_fractal *fractal)
{
    if (keycode == ESC) // if esc is pressed
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
    return (0);    
}