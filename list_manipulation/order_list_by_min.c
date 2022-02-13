/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list_by_min.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:51:25 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/13 16:00:31 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_list	*get_min_list(t_list *top)
{
	t_list *head;
	int min;

	min = top->content;
	head = top;
	while (top)
	{
		if (min > top->content)
		{
			min = top->content;
			head = top;
		}
		top = top->next;
	}
	return (head);
}

void	order_list_by_min(t_list **top)
{
	t_list *node;
	int		pos;
	int		times;

	node = get_min_list(*top);
	pos = get_pos_by_node(*top, node);
	if (pos <= ft_lstsize(*top) / 2)
		times = pos;
	else
		times = pos - ft_lstsize(*top);
	while (times > 0 && rotate(top))
	{
		//printf("ra\n");
		times--;
	}
	while (times < 0 && reverse(top))
	{
		//printf("rra\n");
		times++;
	}
}