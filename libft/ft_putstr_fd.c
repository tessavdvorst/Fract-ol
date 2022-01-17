/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/01 14:11:12 by tvan-der      #+#    #+#                 */
/*   Updated: 2021/09/30 13:13:28 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	if (s != NULL)
	{
		len = ft_strlen(s);
		write(fd, s, len);
	}
	return (len);
}
