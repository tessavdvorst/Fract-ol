// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        ::::::::            */
// /*   mandelbrot.c                                       :+:    :+:            */
// /*                                                     +:+                    */
// /*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
// /*                                                   +#+                      */
// /*   Created: 2022/01/24 11:24:55 by tvan-der      #+#    #+#                 */
// /*   Updated: 2022/01/25 12:47:16 by tvan-der      ########   odam.nl         */
// /*                                                                            */
// /* ************************************************************************** */

#include "../fractol.h"

int mandelbrot(t_complex z, t_complex complex)
{
    int n;

    n = 0;
    while (absolute_complex(z) < 4 && (n < MAX_ITERATIONS))
    {
        z = square_complex(z);
        z = add_complex(z, complex);
        n++;
    }
    return (n);
}

void draw_mandelbrot(t_fractal *fractal)
{
    int x;
    int y;
    t_complex z;
    t_complex complex;
    int     iter;

    y = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WIDTH)
        {
            complex.re = x * (((fractal->max_r - fractal->min_r)/WIDTH) * fractal->zoom) + fractal->offset_r * fractal->zoom;
            complex.im = y * (((fractal->max_i - fractal->min_i)/HEIGTH) * fractal->zoom) + fractal->offset_i * fractal->zoom;
            z.re = complex.re;
            z.im = complex.im;
            iter = mandelbrot(z, complex);
            if (iter != MAX_ITERATIONS)
                my_mlx_pixel_put(fractal, x, y, color(fractal, iter));
            else
                my_mlx_pixel_put(fractal, x, y, BLACK);
            x++;
        }
        y++;
    }
}

void mandelbrot_init(t_fractal *fractal)
{
    fractal->min_r = -2.0;
    fractal->max_r = 2.0;
    fractal->min_i = -1.5;
    fractal->max_i = 1.5;
    fractal->offset_r = -2.5;
    fractal->offset_i = -1.5;
}