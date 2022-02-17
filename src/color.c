/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 10:17:28 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/17 13:27:26 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_r(int rgb)
{
	return ((rgb >> 16));
}

int	get_g(int rgb)
{
	return ((rgb >> 8) & 0xFF);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

// A function that accepts a double (distance) and a int (color) as arguments, 
// 0 will add no shading to the color, 
// 1 will make the color completely dark. 
// 0.5 will dim it halfway
// 0.25 a quarter way.

int	color_pastel(int n)
{
	if (n < 3)
		return (0x00FFB3BA);
	else if (n < 6)
		return (0x00FFDFBA);
	else if (n < 9)
		return (0x00FFFFBA);
	else if (n < 12)
		return (0x00BAFFC9);
	else if (n < 15)
		return (0xBAE1FF);
	else if (n < 18)
		return (0x00FFB3BA);
	else if (n < 21)
		return (0x00FFDFBA);
	else if (n < 24)
		return (0x00FFFFBA);
	else if (n < 27)
		return (0x00BAFFC9);
	else if (n < 30)
		return (0xBAE1FF);
	else
		return (0x00000000);
}

int	color_neon(int n)
{
	if (n < 3)
		return (0x005FE8FF);
	else if (n < 6)
		return (0x0064FF00);
	else if (n < 9)
		return (0x00E7FF00);
	else if (n < 12)
		return (0x00FC49AB);
	else if (n < 15)
		return (0x00FF7300);
	else if (n < 18)
		return (0x005FE8FF);
	else if (n < 6)
		return (0x0064FF00);
	else if (n < 9)
		return (0x00E7FF00);
	else if (n < 12)
		return (0x00FC49AB);
	else if (n < 15)
		return (0x00FF7300);
	else
		return (0x00000000);
}

// void	make_black_window(t_fractal *fractal)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WIDTH)
// 	{
// 		j = 0;
// 		while (j < HEIGTH)
// 		{
// 			my_mlx_pixel_put(fractal, i, j, 0x00000000);
// 			j++;
// 		}
// 		i++;
// 	}
// }

// int	color_neon(int n)
// {
// 	if (n < 4)
// 		return (0x0075D5FD);
// 	else if (n < 8)
// 		return (0x00B76CFD);
// 	else if (n < 12)
// 		return (0x00FF2281);
// 	else if (n < 16)
// 		return (0x00011FFD);
// 	else if (n < 20)
// 		return (0x0075D5FD);
// 	else if (n < 24)
// 		return (0x00B76CFD);
// 	else if (n < 28)
// 		return (0x00FF2281);
// 	else if (n < 32)
// 		return (0x00011FFD);
// 	else
// 		return (0x00000000);
// } 

int  add_shade(double distance, int color)
{
    int r;
    int g;
    int b;
    int newcolor;
    
    //parse separate color values
    r = get_r(color);
    g = get_g(color);
    b = get_b(color);
    //printf("the color: %X\n red values: %X (%d), green values: %X (%d), blue values: %X (%d)\n", color, r, r, g, g, b, b);
    
    //add shade and update separate color values
    r = r - floor((255 * distance));
    if (r > 255)
        r = 255;
    else if (r < 0)
        r = 0;
    
    g = g - floor((255 * distance));
    if (g > 255)
        g = 255;
    else if (g < 0) 
        g = 0;
    
    b = b - floor((255 * distance));
    if (b > 255)
        b = 255;
    else if (b < 0)
        b = 0;
    //printf("After adding shade -> red values: %X (%d), green values: %X (%d), blue values: %X (%d)\n",r, r, g, g, b, b);
    
    //combine separtes color values to one value
    newcolor = create_rgb(r,g,b);
    return(newcolor);    
}

// a function that accepts a int (color) as argument and that will invert the color accordingly.
// int  get_opposite(int color)
// int  gradient(int startcolor, int endcolor, int len, int pix)