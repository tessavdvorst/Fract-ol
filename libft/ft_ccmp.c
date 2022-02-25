/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ccmp.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/24 11:22:17 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/24 12:06:30 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ccmp(const char c1, const char c2)
{
	if ((unsigned char)c1 && (unsigned char)c2
		&& (unsigned char)c1 == (unsigned char)c2)
		return (0);
	return (1);
}
