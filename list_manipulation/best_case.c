/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:18:42 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/17 13:21:29 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	case_1(t_list *top_a, t_list *top_b, t_postion *pos, int *tab)
{
	t_list	*node;

	node = ft_lstlast(top_a);
	if (top_b->content < top_a->content && top_b->content > node->content)
	{
		pos[pos->index].pos_a = 0;
		if (pos[pos->index].pos_b > 0)
			tab[pos->index] = pos[pos->index].pos_b;
		else
			tab[pos->index] = ft_abs(pos[pos->index].pos_b);
		return (1);
	}
	return (0);
}

void	set_tab(int	*tab, t_postion	*pos)
{
	int	a;
	int	b;

	a = pos[pos->index].pos_a;
	b = pos[pos->index].pos_b;
	if ((a >= 0 && b >= 0) || (a <= 0 && b <= 0))
		tab[pos->index] = max_of_two_number(ft_abs(a), ft_abs(b));
	else
		tab[pos->index] = ft_abs(a) + ft_abs(b);
}

int	case_2(t_list *top_a, t_list *top_b, t_postion *pos, int *tab)
{
	t_list	*node;
	int		j;

	node = top_a;
	j = 0;
	while (node->next)
	{
		if (top_b->content > node->content && node->next->content > \
		top_b->content)
		{
			if (j <= ft_lstsize(top_a) / 2)
				pos[pos->index].pos_a = j + 1;
			else
				pos[pos->index].pos_a = j + 1 - ft_lstsize(top_a);
			set_tab(tab, pos);
			break ;
		}
		j++;
		node = node->next;
	}
	return (node->next != NULL);
}

void	case_3(t_list *top_a, t_postion *pos, int *tab)
{
	t_list	*node;
	int		j;
	int		x;
	int		y;

	node = get_max_list(top_a);
	j = get_pos_by_node(top_a, node);
	if (j <= ft_lstsize(top_a) / 2)
		pos[pos->index].pos_a = j + 1;
	else
		pos[pos->index].pos_a = j + 1 - ft_lstsize(top_a);
	x = pos[pos->index].pos_a;
	y = pos[pos->index].pos_b;
	if (x >= 0 && y >= 0)
		tab[pos->index] = max_of_two_number(x, y);
	else if (x <= 0 && y <= 0)
		tab[pos->index] = max_of_two_number(ft_abs(x), ft_abs(y));
	else
		tab[pos->index] = ft_abs(x) + ft_abs(y);
}
