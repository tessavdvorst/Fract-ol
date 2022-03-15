/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/09 12:25:26 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/15 14:47:11 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol_bonus.h"

int	read_c(t_fractal *fractal, char *str, char c)
{
	double	num;

	num = 0.0;
	if (str)
		num = ft_atof(str);
	if (num != 0.0)
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
	return (0);
}

int	read_fractal(t_fractal *fractal, char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
	{
		fractal->name = 'm';
		return (1);
	}
	else if (ft_strcmp(str, "julia") == 0)
	{
		fractal->name = 'j';
		fractal->julia_r = 0.0;
		fractal->julia_i = 0.0;
		return (1);
	}
	else
	{
		print_error();
		return (0);
	}
}

int	info_init(t_fractal *fractal, char **str, int argc)
{
	int	check;

	check = 0;
	fractal->color = 0;
	if (argc > 1)
		check = read_fractal(fractal, &str[1][0]);
	if (argc > 2)
	{
		if (ft_ccmp(fractal->name, 'j') == 0)
		{
			if (ft_strcmp(str[2], "0") != 0
				&& (read_c(fractal, str[2], 'r') == 0))
				print_error();
			if (str[3] && (ft_strcmp(str[3], "0") != 0
					&& (read_c(fractal, str[3], 'i') == 0)))
				print_error();
		}
		else
		{
			check = 0;
			print_error();
		}
	}
	return (check);
}
