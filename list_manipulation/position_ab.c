/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 13:21:17 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	set_pos_b(t_list *top_b, t_postion *pos)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(top_b);
	while (i < size)
	{
		if (i <= size / 2)
			pos[i].pos_b = i;
		else
			pos[i].pos_b = i - size;
		i++;
	}
}

void	set_pos_a(t_list *top_a, t_list *top_b, t_postion *pos, int *tab)
{
	pos->index = 0;
	while (top_b)
	{
		if (case_1(top_a, top_b, pos, tab))
		{
			pos->index++;
			top_b = top_b->next;
			continue ;
		}
		if (case_2(top_a, top_b, pos, tab))
		{
			pos->index++;
			top_b = top_b->next;
			continue ;
		}
		case_3(top_a, pos, tab);
		pos->index++;
		top_b = top_b->next;
	}
}

void	find_position(t_list **top_a, t_list **top_b)
{
	t_postion	*pos;
	int			*tab;
	int			i;

	pos = malloc(sizeof(t_postion) * ft_lstsize(*top_b));
	tab = malloc(sizeof(int) * ft_lstsize(*top_b));
	set_pos_b(*top_b, pos);
	set_pos_a(*top_a, *top_b, pos, tab);
	i = 0;
	i = min_of_arr(tab, ft_lstsize(*top_b));
	apply_sort(top_a, top_b, pos, i);
	free(pos);
	free(tab);
}
