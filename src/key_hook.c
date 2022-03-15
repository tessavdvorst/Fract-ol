/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_hook.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:18:27 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/15 13:42:44 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
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
