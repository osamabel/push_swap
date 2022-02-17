/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_min_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:49:45 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:05:24 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_list	*get_min_list(t_list *top)
{
	t_list	*head;
	int		min;

	min = top->content;
	head = top;
	top = top->next;
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
