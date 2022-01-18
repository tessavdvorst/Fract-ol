/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   openwin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 11:13:31 by Tessa         #+#    #+#                 */
/*   Updated: 2022/01/18 15:16:53 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		color = 0x2FA8F9;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 750, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 750);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	color = add_shade(0.5, color);
	printf("after adding shade the color will be: %X\n", color);	
	draw_pink_square_outline(img, 500, 375);
	draw_blank_space(img, 85, 225);
	bres_draw_blue_circle(img, 750, 175, 50);
	draw_rainbow_square(img);
	draw_shade(img);
	//draw_line(img, 125, 350, 200);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
