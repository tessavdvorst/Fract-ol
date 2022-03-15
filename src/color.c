/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/18 10:17:28 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/15 14:44:39 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	color(int n)
{
	int	r;
	int	g;
	int	b;

	r = 0;
	g = 10;
	b = 0 + floor(n * 10);
	return (create_rgb(r, g, b));
}
