/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/19 16:07:04 by Tessa         #+#    #+#                 */
/*   Updated: 2020/11/23 14:10:50 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ptr_s;

	ptr_s = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr_s[i] = '\0';
		i++;
	}
}
