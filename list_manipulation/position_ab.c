/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/10 16:01:40 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int is_between(int x, int a, int b)
{
	return ((x > a && x < b) || (x < a && x > b));
}

void	set_pos_b(t_list *top_b, t_postion *pos)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_lstsize(top_b);
	while (i <= size / 2)
	{
		pos[i].pos_b = i;
		i++;
	}
	j = i - 1;
	if (size % 2 == 0)
		j--;
	while (j >= 1)
	{
		pos[i].pos_b = -j;
		j--;
		i++;
	}
}

void	set_pos_a(t_list *top_a, t_list *top_b, t_postion *pos)
{
	t_list *nodehead;
	t_list *node;
	int		midle;
	int		i;
	int		j;

	i = 0;
	while (top_b)
	{
		head = top_a;
		node = ft_lstlast(top_a);
		if (is_between(top_b->content, head->content, node->content))
			pos[i].pos_a = i;
		else if (i == 0)
		{
			j = ft_lstsize(top_b) - 1;
			while  (head->next != node)
			{
				if (is_between(top_b->content, head->content, head->next->content))
				{
					pos[i].pos_a = get_position_by_node(head);
					i++;
					break ;
				}
				if (is_between(top_b->content, node->content, node->prev->content))
				{
					pos[j].pos_a = get_position_by_node(node);
					j--;
					break ;
				}
				head = head->next;
				node = node->prev;
			}
		}
		else
		{
			head = max_in_list(top_a);
			node = max_in_list(top_b);
		}
		top_b = top_b->next;
	}
}

void find_position(t_list *top_a, t_list *top_b)
{
	t_postion *pos;
	int i;

	t_list *n = top_a;
	top_a = n;
	i = 0;
	pos = malloc(sizeof(t_postion) * ft_lstsize(top_b));
	set_pos_b(top_b, pos);
	set_pos_b(top_a, pos);
	set_pos_a(top_a, top_b, pos);
	i = 0;
	printf("\n");
	while (i < ft_lstsize(top_b))
	{
		printf(">> %i\n", pos[i].pos_b);
		i++;
	}
}