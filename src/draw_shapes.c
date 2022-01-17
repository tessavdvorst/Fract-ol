/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_shapes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 11:50:16 by Tessa         #+#    #+#                 */
/*   Updated: 2022/01/13 17:14:11 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void pixel_circle(t_data img, int xc,int yc,int x,int y)
{
	my_mlx_pixel_put(&img,xc+x,yc+y,0x73d9e7);
	my_mlx_pixel_put(&img,xc+x,yc-y,0x73d9e7);
	my_mlx_pixel_put(&img,xc-x,yc+y,0x73d9e7);
	my_mlx_pixel_put(&img,xc-x,yc-y,0x73d9e7);
	my_mlx_pixel_put(&img,xc+y,yc+x,0x73d9e7);
	my_mlx_pixel_put(&img,xc+y,yc-x,0x73d9e7);
	my_mlx_pixel_put(&img,xc-y,yc+x,0x73d9e7);
	my_mlx_pixel_put(&img,xc-y,yc-x,0x73d9e7);
}

//Function for drawing a circle using Bresenham's algorithm
void    bres_draw_blue_circle(t_data img, int xc, int yc, int r)
{
    int x;
    int y;
    int p;
    
    x = 0;
	y = r;
	p = 3 - 2 * r;
	pixel_circle(img,xc,yc,x,y);
	
	while(x < y)
	{
		if(p < 0)
		{
			x++;
			p = p + 4 * x + 6;
		}
		else
		{
			x++;
			y--;
			p = p + 4 * (x - y) + 10;
		}
		pixel_circle(img,xc,yc,x,y);
	}
}

void	draw_red_square(t_data img, int sx, int sy)
{
    int i;
    int j;
    
	i = 0;

	while (i < 50)
	{
		j = 0;
        while (j < 100)
        {
            my_mlx_pixel_put(&img, sx, sy, 0x00FF0000);
		    sx++;
            j++;
        }
        my_mlx_pixel_put(&img, sx, sy, 0x00FF0000);
        sy++;
        j = 0;
        while (j < 100)
        {
            my_mlx_pixel_put(&img, sx, sy, 0x00FF0000);
		    sx--;
            j++;
        }
        my_mlx_pixel_put(&img, sx, sy, 0x00FF0000);
        sy++;
		i++;
	}
}

void	draw_pink_square_outline(t_data img, int sx, int sy)
{
	int i;
    
    printf("this is the starting position: %d,%d\n", sx, sy);
	// top square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sx++;
		i++;
	}
    
    printf("the current position: %d, %d\n", sx, sy);

	// right side square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sy++;
		i++;
	}

    printf("the current position: %d, %d\n", sx, sy);

	// bottom side square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sx--;
		i++;
	}

    printf("the current position: %d, %d\n", sx, sy);

	// left side square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sy--;
		i++;
	}
	
    printf("the current position: %d, %d\n", sx, sy);
}