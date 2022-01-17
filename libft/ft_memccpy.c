/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <Tessa@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/18 12:34:35 by Tessa         #+#    #+#                 */
/*   Updated: 2020/11/26 15:25:39 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr_dst;
	unsigned const char	*ptr_src;
	size_t				i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
		{
			return (&dst[i + 1]);
		}
		i++;
	}
	return (NULL);
}
