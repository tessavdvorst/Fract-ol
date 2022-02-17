/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:11:20 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/17 15:51:46 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void print_error(void)
{
	printf("\033[38;5;1mInput is invalid.\033[38;5;255m\n"
			"usage: ./fractol [fractalname] [colorway] [julia-re] [julia-im]\n\n"
			"\033[38;5;2mfractalname:\033[38;5;255m\tmandelbrot;\n(mandatory)\tjulia\n\n"
			"\033[38;5;2mcolorway:\033[38;5;255m\tneon;\n(optional)\tpastel\n\n"
			"\033[38;5;2mjulia-re\n"
			"& julia-im:\033[38;5;255m\treal and imaginary coordinates,\n(optional)\te.g. -0.8 and 0.6 (Only for julia set)\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
    t_fractal  fractal;
    int        input;

	if (argc <= 1)
		print_error();
	input = read_input(&fractal, argv, argc);
	//printf("fractal name: %s\n", fractal.name);
	if (input)
	{
        window_init(&fractal);
    	mlx_hook(fractal.win, 2, 0, key_hook, &fractal);//&fractal);
    	mlx_hook(fractal.win, 17, 0, ft_close, &fractal);//&fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_loop(fractal.mlx);
	} 
	return (0);
}