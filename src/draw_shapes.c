/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_shapes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/13 11:50:16 by Tessa         #+#    #+#                 */
/*   Updated: 2022/01/18 15:39:21 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void pixel_circle(t_data img, int xc,int yc,int x,int y)
{
	my_mlx_pixel_put(&img,xc+x,yc+y,0x181FE4);
	printf("(%d,%d)", xc+x, yc+y);
	my_mlx_pixel_put(&img,xc+x,yc-y,0x181FE4);
	printf("(%d,%d", xc+x, yc-y);
	my_mlx_pixel_put(&img,xc-x,yc+y,0x181FE4);
	printf("(%d,%d)", xc-x, yc+y);
	my_mlx_pixel_put(&img,xc-x,yc-y,0x0790D4);
	printf("(%d,%d)", xc-x, yc-y);
	my_mlx_pixel_put(&img,xc+y,yc+x,0x0790D4);
	printf("(%d,%d)", xc+x, yc+y);
	my_mlx_pixel_put(&img,xc+y,yc-x,0x73d9e7);
	printf("(%d,%d)", xc+x, yc-y);
	my_mlx_pixel_put(&img,xc-y,yc+x,0x73d9e7);
	printf("(%d,%d)", xc-x, yc+y);
	my_mlx_pixel_put(&img,xc-y,yc-x,0x73d9e7);
	printf("(%d,%d)", xc-x, yc-y);
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

void	draw_rectangle(t_data img, int sx, int sy, int width, int height, int color)
{
	int i;
    int j;
    
	i = 0;
	while (i < height)
	{
		j = 0;
        while (j < width) // line to the right
        {
            my_mlx_pixel_put(&img, sx, sy, color);
		    sx++;
            j++;
        }
        my_mlx_pixel_put(&img, sx, sy, color); // 
        sy++;
        j = 0;
        while (j < width)
        {
            my_mlx_pixel_put(&img, sx, sy, color);
		    sx--;
            j++;
        }
        my_mlx_pixel_put(&img, sx, sy, color);
        sy++;
		i++;
	}
}

void	draw_rainbow_square(t_data img)
{
	draw_rectangle(img, 250, 500, 350, 12, 0xFF0000);
	draw_rectangle(img, 250, 525, 350, 12, 0xFF8000);
	draw_rectangle(img, 250, 550, 350, 12, 0xFFFF00);
	draw_rectangle(img, 250, 575, 350, 12, 0x00FF00);
	draw_rectangle(img, 250, 600, 350, 12, 0x00FFFF);
	draw_rectangle(img, 250, 625, 350, 12, 0x0000FF);
	draw_rectangle(img, 250, 650, 350, 12, 0x7F00FF);	
}

void	draw_shade(t_data img)
{
	draw_rectangle(img, 125, 250, 200, 12, 0x00FFFF);
	draw_rectangle(img, 125, 275, 200, 12, add_shade(0.2, 0x00FFFF));
	draw_rectangle(img, 125, 300, 200, 12, add_shade(0.4, 0x00FFFF));
	draw_rectangle(img, 125, 325, 200, 12, add_shade(0.6, 0x00FFFF));
	draw_rectangle(img, 125, 350, 200, 12, add_shade(0.8, 0x00FFFF));
	draw_rectangle(img, 125, 375, 200, 12, add_shade(1, 0x00FFFF));
	
}

int	gradient(int startcol, int endcol)
{
	double increment[3];
    int sr, er;
    int sg, eg;
    int sb, eb;
    int newcol;
    
    //parse separate color values
    sr = get_r(startcol);
    sg = get_g(startcol);
    sb = get_b(startcol);
	
	er = get_r(endcol);
    eg = get_g(endcol);
    eb = get_b(endcol);
	
    increment[0] = (double)((R(endcolor)) - (R(startcolor))) / (double)len;
    increment[1] = (double)((G(endcolor)) - (G(startcolor))) / (double)len;
    increment[2] = (double)((B(endcolor)) - (B(startcolor))) / (double)len;

    new[0] = (R(startcolor)) + ft_round(pix * increment[0]);
    new[1] = (G(startcolor)) + ft_round(pix * increment[1]);
    new[2] = (B(startcolor)) + ft_round(pix * increment[2]);

    newcol = create_rgb(r,g,b);
    return (newcol);
}

void	draw_line(t_data img, int sx, int sy, int length)
{
	int i;
	
	i = 0;
	while (i < length)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xFFFFFF);
		sx++;
		i++;
	}
}
void	draw_blank_space(t_data img, int sx, int sy)
{
    int i;
    int j;
    
	i = 0;

	while (i < 100)
	{
		j = 0;
        while (j < 300) // line to the right
        {
            my_mlx_pixel_put(&img, sx, sy, 0xE0FFFF);
		    sx++;
            j++;
        }
        my_mlx_pixel_put(&img, sx, sy, 0xE0FFFF); // 
        sy++;
        j = 0;
        while (j < 300)
        {
            my_mlx_pixel_put(&img, sx, sy, 0xE0FFFF);
		    sx--;
            j++;
        }
        my_mlx_pixel_put(&img, sx, sy, 0xE0FFFF);
        sy++;
		i++;
	}
}

void	draw_pink_square_outline(t_data img, int sx, int sy)
{
	int i;
    
    //printf("this is the starting position: %d,%d\n", sx, sy);
	// top square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sx++;
		i++;
	}
    
    //printf("the current position: %d, %d\n", sx, sy);

	// right side square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sy++;
		i++;
	}

    //printf("the current position: %d, %d\n", sx, sy);

	// bottom side square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sx--;
		i++;
	}

    //printf("the current position: %d, %d\n", sx, sy);

	// left side square
	i = 0;
	while (i < 100)
	{
		my_mlx_pixel_put(&img, sx, sy, 0xd794d4);
		sy--;
		i++;
	}
	
    //printf("the current position: %d, %d\n", sx, sy);
}