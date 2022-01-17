/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 17:04:47 by tvan-der      #+#    #+#                 */
/*   Updated: 2021/09/23 14:07:42 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize > len_dst)
	{
		i = len_dst;
		j = 0;
		while (i < (dstsize - 1) && j < len_src)
		{
			dst[i] = src[j];
			i++;
			if (len_src != 0)
				j++;
		}
		dst[i] = '\0';
		return (len_dst + len_src);
	}
	return (dstsize + len_src);
}
