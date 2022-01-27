/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   openwin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 11:13:31 by Tessa         #+#    #+#                 */
/*   Updated: 2022/01/27 15:35:45 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int closed(int keycode, t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);    
}

int	main(void)
{
	t_data	img;
    t_vars  vars;
	//int		color = 0x2FA8F9;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1000, 750, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1000, 750);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//color = add_shade(0.5, color);
	//printf("after adding shade the color will be: %X\n", color);	
	//draw_pink_square_outline(img, 500, 375);
	//draw_blank_space(img, 85, 225);
	//bres_draw_blue_circle(img, 750, 175, 50);
	//draw_rainbow_square(img);
	//draw_shade(img);
    plotCplane(img);
    //draw_line(img, 125, 350, 200);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    mlx_hook(vars.win, 2, 1L<<0, closed, &vars);
	mlx_loop(vars.mlx);
}
