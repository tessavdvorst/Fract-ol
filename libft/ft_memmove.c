/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:56:31 by Tessa         #+#    #+#                 */
/*   Updated: 2020/11/26 12:09:07 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptr_dst = (char *)dst;
	ptr_src = (const char *)src;
	if (ptr_dst < ptr_src)
		ptr_dst = ft_memcpy(ptr_dst, ptr_src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			ptr_dst[i - 1] = ptr_src[i - 1];
			i--;
		}
	}
	return (dst);
}
