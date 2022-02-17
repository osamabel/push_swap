/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_max_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:50:22 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:05:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_list	*get_max_list(t_list *top)
{
	t_list	*head;
	int		max;

	max = top->content;
	head = top;
	top = top->next;
	while (top)
	{
		if (max < top->content)
		{
			max = top->content;
			head = top;
		}
		top = top->next;
	}
	return (head);
}
