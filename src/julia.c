/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:15:01 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/17 12:52:54 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int julia(t_complex z, t_complex complex)
{
    int count;

    count = 0;
    while ((z.re * z.re + z.im * z.im) < 4 && (count < MAX_ITERATIONS))
    {
        z = square_complex(z);
        z = add_complex(z, complex);
        count++;
    }
    if (count == MAX_ITERATIONS)
        return (count);
        
    return (count + 1 - log(log2(z.re * z.re + z.im * z.im)));
}

void draw_julia(t_fractal *fractal)
{
    int x;
    int y;
    t_complex z;
    t_complex complex;
    //int r, g, b;
    int     iter;

    y = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WIDTH)
        {
            z.re = x * (((fractal->max_x - fractal->min_x)/WIDTH) * fractal->zoom) + fractal->offset_x * fractal->zoom;// * img.zoom;
            z.im = y * (((fractal->max_y - fractal->min_y)/HEIGTH) * fractal->zoom) + fractal->offset_y * fractal->zoom;// * img.zoom;
            //printf("%f\n", fractal.img.zoom);
            complex.re = -0.4;//-0.8;//0.285; //
            complex.im = 0.6;//0.156;//0.01;//
            iter = julia(z, complex);
            // r = 255 * iter / MAX_ITERATIONS;
            // g = 100;
            // if (iter < MAX_ITERATIONS)
            //     b = 250 - iter / 10;
            // else
            //     b = 0 + iter / 10;
            my_mlx_pixel_put(fractal, x, y, color_pastel(iter));//create_rgb(r,g,b));
            // if (iter != MAX_ITERATIONS)
            // {
            //     r = 255 * iter / MAX_ITERATIONS;
            //     g = 255;
            //     b = 255 - iter * 150 / 50;
            //     my_mlx_pixel_put(&img, x, y, create_rgb(r,g,b));
            // //      // color pixels that do not belong to the mandelbrot set
            // }

            x++;
        }
        y++;
    }
}

void julia_init(t_fractal *fractal)
{
    fractal->min_x = -2.0;
    fractal->max_x = 2.0;
    fractal->min_y = -1.5;
    fractal->max_y = 1.5;
    fractal->offset_x = -2.0;
    fractal->offset_y = -1.5;
}

