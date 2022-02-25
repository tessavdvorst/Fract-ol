/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_hook.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:28:22 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/24 15:46:17 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
    (void)x;
	(void)y;
	//printf("Hello from mouse_code: %d!\n", mousecode);
    if (mousecode == WHEEL_DOWN)
	{		
		fractal->zoom *= 1.05;
		//printf("%f\n", fractal->zoom);
        make_fractal(fractal);
	}
	if (mousecode == WHEEL_UP)
	{		
		fractal->zoom *= 0.95;
		//printf("%f\n", fractal->zoom);
        make_fractal(fractal);
	}
    return (0);
}