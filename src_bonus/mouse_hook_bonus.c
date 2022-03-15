/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mouse_hook_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:28:22 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/15 14:04:19 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol_bonus.h"

int	mouse_hook(int mousecode, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (mousecode == WHEEL_DOWN)
	{
		fractal->zoom *= 1.05;
		draw_fractal(fractal);
	}
	if (mousecode == WHEEL_UP)
	{
		fractal->zoom *= 0.95;
		draw_fractal(fractal);
	}
	return (0);
}
