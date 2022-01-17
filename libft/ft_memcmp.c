/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 14:28:26 by tvan-der      #+#    #+#                 */
/*   Updated: 2020/11/18 10:20:32 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*ptr_s1;
	char	*ptr_s2;
	size_t	i;

	ptr_s1 = (char *)s1;
	ptr_s2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)ptr_s1[i] != (unsigned char)ptr_s2[i])
			return ((unsigned char)ptr_s1[i] - (unsigned char)ptr_s2[i]);
		i++;
	}
	return (0);
}
