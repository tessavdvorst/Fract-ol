/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_num.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 13:44:38 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/03/14 17:21:36 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnbr(int n, t_data *data)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			data->print_count += 11;
		}
		else
		{
			ft_printchar('-', data);
			ft_printnbr((-1 * n), data);
		}
	}
	else if (n > 9)
	{
		ft_printnbr((n / 10), data);
		ft_printnbr((n % 10), data);
	}
	else
		ft_printchar((n + '0'), data);
}

void	ft_print_unsignednbr(unsigned int n, t_data *data)
{
	if (n > 9)
	{
		ft_print_unsignednbr((n / 10), data);
		ft_print_unsignednbr((n % 10), data);
	}
	else
		ft_printchar((n + '0'), data);
}

void	ft_printhexa(unsigned long n, char *basestr, t_data *data)
{
	if (n >= 16)
		ft_printhexa((n / 16), basestr, data);
	ft_printchar(basestr[(n % 16)], data);
}

void	ft_printptr(void *ptr, t_data *data)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	ft_printstr("0x", data);
	ft_printhexa(p, "0123456789abcdef", data);
}
