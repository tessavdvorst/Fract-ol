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

int mandelbrot(t_complex z, t_complex complex)
{
    int count;

    count = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && (count < MAX_ITERATIONS))
    {
        z = square_complex(z);
        z = add_complex(z, complex);
        count++;
    }
    return (count);
}

void draw_mandelbrot(t_fractal *fractal)
{
    int x;
    int y;
    t_complex z;
    t_complex complex;
    int color;
    //int r, g, b;
    int     iter;

    y = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WIDTH)
        {
            complex.re = x * (((MAX_X - MIN_X)/WIDTH) * fractal->zoom) + fractal->offset_x * fractal->zoom;
            complex.im = y * (((MAX_Y - MIN_Y)/HEIGTH) * fractal->zoom) + fractal->offset_y * fractal->zoom;
            z.re = complex.re;
            z.im = complex.im;
            iter = mandelbrot(z, complex);
            color = 255 - (int)(iter * 255 / MAX_ITERATIONS);
            my_mlx_pixel_put(fractal, x, y, create_rgb(color, color, color));
            // if (iter != 100)
            // {
            //     r = 255 - floor(iter * 150 / 10);
            //     g = 255 - floor(iter * 200 / 20);
            //     b = 255 - floor(iter * 150 / 10);
            //     my_mlx_pixel_put(fractal, x, y, create_rgb(r,g,b));
            //      // color pixels that do not belong to the mandelbrot set
            // }
            x++;
        }
        y++;
    }
}

void mandelbrot_init(t_fractal *fractal)
{
    fractal->min_x = -2.0;
    fractal->max_x = 2.0;
    fractal->min_y = -1.5;
    fractal->max_y = 1.5;
    fractal->zoom = 1;
    fractal->offset_x = -2.5;
    fractal->offset_y = -1.5;
    draw_mandelbrot(fractal);
}