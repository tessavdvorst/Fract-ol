/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 14:35:45 by Tessa         #+#    #+#                 */
/*   Updated: 2020/11/23 14:51:50 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr_b;

	ptr_b = (char *)b;
	i = 0;
	while (i < len)
	{
		ptr_b[i] = (unsigned char)c;
		i++;
	}
	return (ptr_b);
}
