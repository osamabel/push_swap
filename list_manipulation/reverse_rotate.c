/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:09:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 12:47:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	reverse(t_list **top)
{
	t_list	*temp;

	if (ft_lstsize(*top) > 1)
	{
		temp = ft_lstlast(*top);
		temp->prev->next = NULL;
		temp->prev = NULL;
		temp->next = *top;
		(*top)->prev = temp;
		*top = (*top)->prev;
	}
	return (1);
}

int	rrr(t_list **top_a, t_list **top_b)
{
	reverse(top_a);
	reverse(top_b);
	write(1, "rrr\n", 4);
	return (1);
}

int	rra(t_list **top_a)
{
	reverse(top_a);
	write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_list **top_b)
{
	reverse(top_b);
	write(1, "rrb\n", 4);
	return (1);
}
