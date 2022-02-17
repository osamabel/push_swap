/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_node_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:49:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:05:46 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	get_pos_by_node(t_list *top, t_list *node)
{
	int	index;

	index = 0;
	while (top != node)
	{
		index++;
		top = top->next;
	}
	return (index);
}
