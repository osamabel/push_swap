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
	int		counter;

	counter = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
