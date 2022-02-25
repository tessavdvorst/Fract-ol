/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tvan-der <tvan-der@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/23 15:58:09 by tvan-der      #+#    #+#                 */
/*   Updated: 2022/02/25 10:41:57 by tvan-der      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

double tod(const char *str)
{
    int i;
    double dec;
    double num;

    i = 0;
    num = 0.0;
    dec = 10.0;
    while (str && str[i] >= '0' && str[i] <= '9')
    {
        num += (str[i] - '0') / dec;
        dec = dec * 10;
        i++;
    }
    return (num);
}

double ft_atof(const char *str)
{
    int i;
    int isneg;
    double num;
    
    i = 0;
    isneg = 0;
    num = 0.0;
    if (str[i] == '-')
        isneg = 1;
    if (str[i] == '+' || str[i] == '-')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        num = num * 10 + str[i] - '0';
        i++;
    }
    if (str[i] == '.')
        num += tod(str + i + 1);
    if (isneg)
        num = num * -1;
    return (num);
}