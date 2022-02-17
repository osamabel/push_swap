/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:16:07 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 13:21:35 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	optimisation(t_list **top_a, t_list **top_b, t_postion *pos, int min)
{
	while (pos[min].pos_a > 0 && pos[min].pos_b > 0)
	{
		rr(top_a, top_b);
		pos[min].pos_a--;
		pos[min].pos_b--;
	}
	while (pos[min].pos_a < 0 && pos[min].pos_b < 0)
	{
		rrr(top_a, top_b);
		pos[min].pos_a++;
		pos[min].pos_b++;
	}
}

void	apply_sort(t_list **top_a, t_list **top_b, t_postion *pos, int min)
{
	optimisation(top_a, top_b, pos, min);
	while (pos[min].pos_a > 0)
	{
		ra(top_a);
		pos[min].pos_a--;
	}
	while (pos[min].pos_b > 0)
	{
		rb(top_b);
		pos[min].pos_b--;
	}
	while (pos[min].pos_a < 0)
	{
		rra(top_a);
		pos[min].pos_a++;
	}
	while (pos[min].pos_b < 0)
	{
		rrb(top_b);
		pos[min].pos_b++;
	}
	pa(top_a, top_b);
}
