/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/08 12:25:17 by tvan-der      #+#    #+#                 */
/*   Updated: 2020/12/08 12:25:18 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstring;
	unsigned int	len;
	unsigned int	i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	newstring = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (i < len)
	{
		newstring[i] = f(i, s[i]);
		i++;
	}
	newstring[i] = '\0';
	return (newstring);
}
