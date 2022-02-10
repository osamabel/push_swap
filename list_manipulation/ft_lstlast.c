/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:18:21 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/15 09:52:26 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 0;
		while (lst->next)
		{
			lst = lst->next;
			i++;
		}
		return (lst);
	}
	return (0);
}