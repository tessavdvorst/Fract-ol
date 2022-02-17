/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:42:00 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/16 13:42:26 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

// this function takes a complex number, squares it and returns the result
// the real number = (realnumber^2) - (imaginarynumber^2)
// the imaginary number = realnumber * imaginarynumber + realnumber * imaginarynumber
t_complex square_complex(t_complex x)
{
    t_complex z;

    z.re = pow(x.re, 2) - pow(x.im, 2);
    z.im = 2 * x.re * x.im;

    return (z);
}

// this function takes two complex numbers, adds them to each other and returns the result
// the real number = realnumber1 + realnumber2
// the imaginary number = imaginarynumber1 + imaginarynumber2
t_complex add_complex(t_complex x, t_complex y)
{
    t_complex z;

    z.re = x.re + y.re;
    z.im = x.im + y.im;

    return(z);
}

void	my_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->addr + (y * fractal->line_length + x * (fractal->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}