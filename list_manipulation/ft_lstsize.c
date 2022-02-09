/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 00:07:20 by obelkhad          #+#    #+#             */
/*   Updated: 2021/11/14 00:28:54 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		counter;

	counter = 1;
	if (!lst)
		return (0);
	node = lst;
	while (node->next)
	{
		counter++;
		node = node->next;
	}
	return (counter);
}
