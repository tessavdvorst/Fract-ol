/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/01 17:05:47 by tvan-der      #+#    #+#                 */
/*   Updated: 2021/09/23 14:08:56 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && i < len && i < (ft_strlen(haystack)))
		{
			i++;
			j++;
		}
		if (j == ft_strlen(needle))
		{
			temp = i - j;
			return ((char *)&haystack[temp]);
		}
		i++;
	}
	return (NULL);
}
