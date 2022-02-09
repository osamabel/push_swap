/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_middle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:52:06 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/04 13:24:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	get_mid(t_list *top)
{
	int mid;
	int counter;
	t_list *head;

	counter = 0;
	head = top;
	mid = head->content;
	head = head->next;
	while (head)
	{
		if (mid > top->content)
			counter++;
		top = top->next;
	}
	if (counter == ft_lstsize(top) / 2)
		return (mid);
}