/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/02 15:15:01 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/25 13:20:52 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double  julia(t_complex z, t_complex complex)
{
    double  count;

    count = 0.0;
    while (absolute_complex(z) < 4 && (count < MAX_ITERATIONS))
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
    double     iter;

    y = 0;
    while(y < HEIGTH)
    {
        x = 0;
        while(x < WIDTH)
        {
            z.re = x * (((fractal->max_r - fractal->min_r)/WIDTH) * fractal->zoom) + fractal->offset_r * fractal->zoom;// * img.zoom;
            z.im = y * (((fractal->max_i - fractal->min_i)/HEIGTH) * fractal->zoom) + fractal->offset_i * fractal->zoom;// * img.zoom;
            complex.re = fractal->julia_r;
            complex.im = fractal->julia_i;
            iter = julia(z, complex);
            if (iter != MAX_ITERATIONS)
                my_mlx_pixel_put(fractal, x, y, color(fractal, iter));
            else
                my_mlx_pixel_put(fractal, x, y, BLACK);
            x++;
        }
        y++;
    }
}

void julia_init(t_fractal *fractal)
{
    fractal->min_r = -2.0;
    fractal->max_r = 2.0;
    fractal->min_i = -1.5;
    fractal->max_i = 1.5;
    fractal->offset_r = -2.0;
    fractal->offset_i = -1.5;
}

