/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:11:20 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/25 12:39:37 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void print_error(void)
{
	printf("\033[38;5;1mInput is invalid.\033[38;5;255m\n"
			"usage: ./fractol [fractalname] [julia-re] [julia-im] [colorway]\n\n"
			"\033[38;5;2mfractalname:\033[38;5;255m\tmandelbrot\n(mandatory)\tjulia\n\n"
			"\033[38;5;2mjulia-re\n"
			"& julia-im:\033[38;5;255m\treal and imaginary coordinates (only for julia set),\n(optional)\te.g. -0.4 and 0.6 (standard)\n\n"
			"\033[38;5;2mcolorway:\033[38;5;255m\tlollipop (standard)\n(optional)\ttrippy\n\t\tvibrant\n\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
    t_fractal  fractal;
    int        input;

	input = info_init(&fractal, argv, argc);
	if (input)
	{
		window_init(&fractal);
		mlx_hook(fractal.win, 2, 0, key_hook, &fractal);
		mlx_hook(fractal.win, 17, 0, ft_close, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_loop(fractal.mlx);
	}
	else
	{
		print_error();
	}
	return (0);
}