/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   openwin.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/11 11:13:31 by Tessa         #+#    #+#                 */
/*   Updated: 2022/01/13 17:14:22 by Tessa         ########   odam.nl         */
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

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 750, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 750);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	draw_pink_square_outline(img, 500, 375);
	draw_red_square(img, 250, 175);
	bres_draw_blue_circle(img, 750, 175, 50);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
