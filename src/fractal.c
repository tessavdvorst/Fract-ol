/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractal.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 11:24:55 by tvan-der      #+#    #+#                 */
/*   Updated: 2023/05/22 21:26:48 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	mandelbrot(t_complex complex)
{
	int			n;
	t_complex	z;

	n = 0;
	z.re = 0;
	z.im = 0;
	while (absolute_complex(z) < 4 && (n < MAX_ITERATIONS))
	{
		z = square_complex(z);
		z = add_complex(z, complex);
		n++;
	}
	return (n);
}

int	julia(t_fractal *fractal, t_complex z)
{
	int			n;
	t_complex	complex;

	n = 0;
	complex.re = fractal->julia_r;
	complex.im = fractal->julia_i;
	while (absolute_complex(z) < 4 && (n < MAX_ITERATIONS))
	{
		z = square_complex(z);
		z = add_complex(z, complex);
		n++;
	}
	return (n);
}

int	ship(t_complex complex)
{
	int			n;
	t_complex	z;

	n = 0;
	z.re = 0;
	z.im = 0;
	while (absolute_complex(z) < 4 && (n < MAX_ITERATIONS))
	{
		z = get_abs(z);
		z = square_complex(z);
		z = add_complex(z, complex);
		n++;
	}
	return (n);
}
