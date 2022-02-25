/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 14:19:43 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/25 12:28:08 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int ship(t_complex z, t_complex complex)
{
    int n;

    n = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && (n < MAX_ITERATIONS))
    {
        z = get_abs(z);
        z = square_complex(z);
        z = square_complex(z);
        z = add_complex(z, complex);
        n++;
    }
    return (n);
}

void draw_ship(t_fractal *fractal)
{
    int x;
    int y;
    t_complex z;
    t_complex complex;
    //int color;
    int r, g, b;
    int     iter;

    y = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WIDTH)
        {
            complex.re = x * (((fractal->max_r - fractal->min_r)/WIDTH) * fractal->zoom) + fractal->offset_r * fractal->zoom;
            complex.im = y * (((fractal->max_i - fractal->min_r)/HEIGTH) * fractal->zoom) + fractal->offset_i * fractal->zoom;
            z.re = complex.re;
            z.im = complex.im;
            iter = ship(z, complex);
            // color = 255 - (int)(iter * 255 / MAX_ITERATIONS);
            // my_mlx_pixel_put(fractal, x, y, create_rgb(color, color, color));
            if (iter != MAX_ITERATIONS)
            {
                r = 255 - floor(iter * 150 / 10);
                g = 0;//255 - floor(iter * 200 / 20);
                b = 255 - floor(iter * 150 / 10);
                my_mlx_pixel_put(fractal, x, y, create_rgb(r, g, b));//create_rgb(r,g,b));
                 // color pixels that do not belong to the mandelbrot set
            }
            else
                my_mlx_pixel_put(fractal, x, y, BLACK);
            x++;
        }
        y++;
    }
}

void ship_init(t_fractal *fractal)
{
    fractal->min_r = -2.0;
    fractal->max_r = 2.0;
    fractal->min_i = -1.5;
    fractal->max_i = 1.5;
    fractal->offset_r = -2.4;
    fractal->offset_i = -2.0;
}