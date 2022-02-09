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

t_list	*ft_lstlast(t_list *lst, int lo, int hi)
{
	t_list	*current;
	int	i;

	if (lst)
	{
		i = 0;
		current = lst;
		while (current->next && i < hi - lo)
		{
			current = current->next;
			i++;
		}
		return (current);
	}
	return (0);
}
