/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:52:44 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:06:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_list	*get_node_by_value(t_list *top, int position)
{
	int	i;

	i = 0;
	while (top && i < position)
	{
		top = top->next;
		i++;
	}
	if (top)
		return (top);
	return (0);
}
