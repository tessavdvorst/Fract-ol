/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: Tessa <tvan-der@student.codam.nl>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 16:40:43 by Tessa         #+#    #+#                 */
/*   Updated: 2021/01/19 16:17:58 by Tessa         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	else if (*lst == NULL)
		*lst = new;
	else
	{
		ft_lstlast(*lst)->next = new;
		new->next = NULL;
	}
}
