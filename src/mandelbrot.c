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
    while ((z.re * z.re + z.im * z.im) < 4 && (n < MAX_ITERATIONS))
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
    //int color;
    //int r, g, b;
    int     iter;

    y = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WIDTH)
        {
            complex.re = x * (((fractal->max_x - fractal->min_x)/WIDTH) * fractal->zoom) + fractal->offset_x * fractal->zoom;
            complex.im = y * (((fractal->max_y - fractal->min_y)/HEIGTH) * fractal->zoom) + fractal->offset_y * fractal->zoom;
            z.re = complex.re;
            z.im = complex.im;
            iter = mandelbrot(z, complex);
            // color = 255 - (int)(iter * 255 / MAX_ITERATIONS);
            // my_mlx_pixel_put(fractal, x, y, create_rgb(color, color, color));
            if (iter != MAX_ITERATIONS)
            {
                // r = 255 - floor(iter * 150 / 10);
                // g = 255 - floor(iter * 200 / 20);
                // b = 255 - floor(iter * 150 / 10);
                my_mlx_pixel_put(fractal, x, y, color_neon(iter));//create_rgb(r,g,b));
                 // color pixels that do not belong to the mandelbrot set
            }
            else
                my_mlx_pixel_put(fractal, x, y, BLACK);
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
    fractal->offset_x = -2.5;
    fractal->offset_y = -1.5;
}