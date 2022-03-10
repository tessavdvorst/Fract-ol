/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:11:20 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/10 17:13:46 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	print_error(void)
{
	ft_printf("\033[38;5;1mInput is invalid.\033[38;5;255m\n"
		"usage: ./fractol [fractalname] [julia-re] [julia-im] [colorway]\n\n"
		"\033[38;5;2mfractalname:\033[38;5;255m\tmandelbrot\n(mandatory)\tjulia\n\n"
		"\033[38;5;2mjulia-re\n"
		"& julia-im:\033[38;5;255m\treal and imaginary"
		" coordinates (only for julia set),"
		"\n(optional)\te.g. -0.4 and 0.6 (standard)\n\n");
	exit(0);
}

int	main(int argc, char *argv[])
{
	int			input;
	t_fractal	fractal;

	input = info_init(&fractal, argv, argc);
	if (input)
	{
		window_init(&fractal);
		fractal_init(&fractal);
		draw_fractal(&fractal);
		mlx_hook(fractal.win, 2, 0, key_hook1, &fractal);
		mlx_hook(fractal.win, 17, 0, ft_close, &fractal);
		mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_loop(fractal.mlx);
	}
	return (0);
}
