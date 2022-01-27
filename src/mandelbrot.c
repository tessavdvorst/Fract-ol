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

    z.re = x.re * x.re - x.im * x.im;
    z.im = x.re * x.im + x.re * x.im;

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
    while ((z.re * z.re + z.im * z.im) < 4 && (count < 200))
    {
        z = square_complex(z);
        z = add_complex(z, complex);
        count++;
    }
    return (count);
}

void plotCplane(t_data img)
{
    int x;
    int y;
    //int count;
    t_complex z;
    t_complex complex;
    int r, g, b;
    //int color;
    int     iter;
    //int     hue, saturation, value;

    y = 0;
    while(y < 750)
    {
        x = 0;
        while(x < 1000)
        {
            complex.re = x * (3.0/1000) - 2;
            complex.im = y * (2.0/750) - 1;
            z.re = 0;
            z.im = 0;
            iter = mandelbrot(z, complex);
            if (iter != 200)
            {
                r = 0 + floor(iter * 255 / 100);
                g = 0 + floor(iter * 190 / 100);
                b = 0 + floor(iter * 180 / 100);
                my_mlx_pixel_put(&img, x, y, create_rgb(r,g,b));
                 // color pixels that do not belong to the mandelbrot set
            }
            x++;
        }
        y++;
    }
}