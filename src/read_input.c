/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:25:26 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/25 12:21:03 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void read_color(t_fractal *fractal, char *str)
{
    if (ft_strcmp(str, "lollipop") == 0)
        fractal->color = 0;
    else if (ft_strcmp(str, "trippy") == 0)
        fractal->color = 1;
    else if (ft_strcmp(str, "vibrant") == 0)
        fractal->color = 2;
    else
        exit(0);
}

int read_c(t_fractal *fractal, char *str, char c)
{
    double num;
    
    num = 0.0;
    if (str)
        num = ft_atof(str);
    if (num != 0)
    { 
        if (c == 'r')
        {
            fractal->julia_r = num;
            return (1);
        }
        if (c == 'i')
        {
            fractal->julia_i = num;
            return (1);
        }
    }
    return (-1);
}

int read_fractal(t_fractal *fractal, char *str)
{
    if (ft_strcmp(str, "mandelbrot") == 0)
    {
        fractal->name = 'm';
        return (1);
    }
    else if (ft_strcmp(str, "julia") == 0)
    {
        fractal->name = 'j';
        return (1);
    }
    else if (ft_strcmp(str, "ship") == 0)
    {
        fractal->name = 's';
        return (1);
    }
    else
    {
        print_error();
        return (0);
    }
}

int info_init(t_fractal *fractal, char **str, int argc)
{
    int check;
    
    check = 0;
    fractal->julia_r = CONST_RE;
    fractal->julia_i = CONST_IM;
    fractal->color = 0;
    if (argc > 1)
        check = read_fractal(fractal, &str[1][0]);
    if (argc > 2)
    {    
        if (ft_ccmp(fractal->name, 'j') == 0)
        {
            
            check = read_c(fractal, &str[2][0], 'r');
            if (check == -1)
            {    
                fractal->julia_r = CONST_RE;
                print_error();
            }
        }
        else
            read_color(fractal, &str[2][0]);
    }
    if (argc > 3)
    {
        check = read_c(fractal, &str[3][0], 'i');
        if (check == -1)
        {    
            fractal->julia_i = CONST_IM;
            print_error();
        }
    }
    if (argc > 4)
        read_color(fractal, &str[4][0]);
    return (check);
}