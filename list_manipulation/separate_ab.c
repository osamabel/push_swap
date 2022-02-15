/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:10:13 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/15 10:30:20 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int is_existe(int c, int list[])
{
	int i;

	i = 1;
	while (i <= list[0])
	{
		if (c == list[i])
			return 1;
		i++;
	}
	return 0;
}

int	check_keeped_number(t_list *top)
{
	while (top && top->keep == 1)
		top = top->next;
	if (top)
		return 1;
	return 0;
}

void separet_lis(t_list **top_a, t_list **top_b, int *list)
{
	t_list *node;
	int		i;

	i = 0;
	node = *top_a;
	while (node)
	{
		if (is_existe(node->content, list))
			node->keep = 1;
		else
			node->keep = 0;
		node = node->next;
	}

	while (check_keeped_number(*top_a))
	{
		while ((*top_a)->keep)
			ra(top_a);
		pb(top_a, top_b);
		i++;
	}
}