/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/08 14:11:20 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/10 14:44:52 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char *argv[])
{
    t_fractal  fractal;
    int        input;

	if (argc <= 1)
		printf("Input is invalid. Please choose:\n- mandelbrot\n- julia\n");
	input = read_input(&fractal, argv[1]);
	if (input)
	{
        window_init(&fractal);
    	mlx_key_hook(fractal.win, key_hook, &fractal);//&fractal);
		//mlx_mouse_hook(fractal.win, mouse_hook, &fractal);
		mlx_hook(fractal.win, 2, 1L<<0, close_window, &fractal);
		mlx_loop(fractal.mlx);
	} 
	return (0);
}