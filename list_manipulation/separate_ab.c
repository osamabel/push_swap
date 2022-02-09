/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:10:13 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/09 15:27:03 by obelkhad         ###   ########.fr       */
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

void separet_lis(t_list **top_a, t_list **top_b, int *list)
{
	int size;
	int i;

	i = 0;
	size = ft_lstsize(*top_a);
	while (i < size)
	{
		if (!is_existe((*top_a)->content, list))
		{
			push_b(top_b, top_a);
			size--;
		}
		else
			rotate_a(top_a);
		i++;
	}
}