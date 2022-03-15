/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/22 12:35:44 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 17:21:30 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_convert(char c, va_list argp, t_data *data)
{
	if (c == '%')
		ft_printchar(c, data);
	else if (c == 'c')
		ft_printchar(va_arg(argp, int), data);
	else if (c == 'i' || c == 'd')
		ft_printnbr(va_arg(argp, int), data);
	else if (c == 's')
		ft_printstr(va_arg(argp, char *), data);
	else if (c == 'u')
		ft_print_unsignednbr(va_arg(argp, unsigned int), data);
	else if (c == 'x')
		ft_printhexa(va_arg(argp, unsigned int), "0123456789abcdef", data);
	else if (c == 'X')
		ft_printhexa(va_arg(argp, unsigned int), "0123456789ABCDEF", data);
	else if (c == 'p')
		ft_printptr(va_arg(argp, void *), data);
}

int	ft_printf(const char *s, ...)
{
	va_list	argp;
	t_data	data;

	data.print_count = 0;
	va_start(argp, s);
	while (*s != '\0')
	{
		while (*s != '%' && *s)
		{
			ft_printchar(*s, &data);
			s++;
		}
		if (*s)
		{
			s++;
			ft_convert(*s, argp, &data);
			s++;
		}
	}
	va_end(argp);
	return (data.print_count);
}
