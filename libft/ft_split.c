/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 15:22:47 by Tessa         #+#    #+#                 */
/*   Updated: 2021/01/11 14:22:34 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		count++;
	}
	if (i != 0 && s[i - 1] == c)
		count--;
	return (count);
}

char	**make_free(char **arr, int count)
{
	int		i;

	i = 0;
	while (i <= count)
	{
		free(arr[i]);
		i++;
	}
	return (NULL);
}

char	**fill_array(char **arr, char const *s, char c, int len)
{
	int		i;
	int		j;

	j = 0;
	while (*s == c && *s)
		s++;
	while (j < len)
	{
		i = 0;
		while (s[i] != c && s[i])
			i++;
		arr[j] = (char *)malloc(sizeof(char) * (i + 1));
		if (!arr[j])
			return (make_free(arr, j));
		ft_strlcpy(arr[j], s, (i + 1));
		while (s[i] == c && s[i])
		{
			i++;
		}
		s += i;
		j++;
	}
	arr[j] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split_arr;
	int		count;

	if (s == NULL)
		return (NULL);
	count = count_words(s, c);
	split_arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!split_arr)
		return (NULL);
	split_arr = fill_array(split_arr, s, c, count);
	return (split_arr);
}
