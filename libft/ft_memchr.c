/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/17 11:30:40 by tvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 15:26:11 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*x;
	size_t			i;

	i = 0;
	x = (unsigned char *)s;
	while (i < n)
	{
		if (x[i] == (unsigned char)c)
			return ((void *)&x[i]);
		i++;
	}
	return (NULL);
}
