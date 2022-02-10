/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:25:26 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/10 14:38:28 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int read_input(t_fractal *fractal, char *str)
{
    if (str)
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
            printf("Input is invalid. Please choose:\n- mandelbrot\n- julia\n");
    } 
    return (0);
}
