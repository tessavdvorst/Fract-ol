/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 17:57:30 by Tessa         #+#    #+#                 */
/*   Updated: 2020/12/21 15:37:51 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	int		endstr;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	endstr = ft_strlen(s1);
	while (endstr && ft_strchr(set, s1[endstr]))
		endstr--;
	strtrim = ft_substr(s1, 0, (endstr + 1));
	return (strtrim);
}
