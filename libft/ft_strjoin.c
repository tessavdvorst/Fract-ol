/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 15:32:05 by Tessa         #+#    #+#                 */
/*   Updated: 2020/11/30 17:07:57 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join(char *new_str, char const *s1, char const *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		total_size;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!new_str)
		return (NULL);
	join(new_str, s1, s2);
	return (new_str);
}
