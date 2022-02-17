/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:25:26 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/17 15:36:02 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"


int read_options(t_fractal *fractal)
{
    (void)fractal;
    printf("Evaluating options");
    return (0);
}

int read_fractal(t_fractal *fractal, char *str)
{
    if (ft_strcmp(str, "mandelbrot") == 0)
    {
        fractal->name = "m";
        return (1);
    }
    else if (ft_strcmp(str, "julia") == 0)
    {
        fractal->name = "j";
        return (1);
    }
    else
    {
        print_error();
        return (0);
    }
}

int read_input(t_fractal *fractal, char **str, int count)
{
    if (*str)
    {
        if (count == 2)
        {    
            if (read_fractal(fractal, str[1]) == 1)
                return (1);
        }
        else if (count > 2)
        {
            if (read_options(fractal) == 1)
                return (1);
        }
    }
    return (0);
}
