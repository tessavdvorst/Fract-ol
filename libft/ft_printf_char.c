/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_char.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/20 12:04:51 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 17:21:33 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printchar(char c, t_data *data)
{
	ft_putchar_fd(c, 1);
	data->print_count++;
}

void	ft_printstr(char *s, t_data *data)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	while (*s != '\0')
	{
		ft_printchar(*s, data);
		s++;
	}
}
