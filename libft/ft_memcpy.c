/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:29:27 by tvan-der      #+#    #+#                 */
/*   Updated: 2020/11/26 14:14:47 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr_dst;
	char	*ptr_src;
	size_t	i;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (n == 0 || (ptr_dst == NULL && ptr_src == NULL))
		return (dst);
	i = 0;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		i++;
	}
	return ((void *)ptr_dst);
}
