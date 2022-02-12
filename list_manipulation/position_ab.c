/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/12 20:34:00 by obelkhad         ###   ########.fr       */
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

int ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return x;
}

void	set_pos_a(t_list *top_a, t_list *top_b, t_postion *pos ,int *tab)
{
	t_list	*node;
	int		i;
	int		j;

	i = 0;
	while (top_b)
	{
		j = 0;
		// node = ft_lstlast(top_a);
		// if (is_between(top_b->content, top_a->content, node->content))
		// {
		// 	pos[i].pos_a = 0;
		// 	//i++;
		// 	//top_b = top_b->next;
		// }
		node = top_a;
		while (node->next)
		{
			if (is_between(top_b->content, node->content, node->next->content))
			{
				if (j <= ft_lstsize(top_a) / 2)
					pos[i].pos_a = j + 1;
				else
					pos[i].pos_a = j - ft_lstsize(top_a);
				tab[i] = ft_abs(pos[i].pos_a) + ft_abs(pos[i].pos_b);
				break ;
			}
			j++;
			node = node->next;
		}
		if (node->next)
		{
			i++;
			top_b = top_b->next;
			continue;
		}
		node = get_max_list(top_a);
		j = get_pos_by_node(top_a, node);
		if (j <= ft_lstsize(top_a) / 2)
			pos[i].pos_a = j + 1;
		else
			pos[i].pos_a = j - ft_lstsize(top_a);
		tab[i] = ft_abs(pos[i].pos_a) + ft_abs(pos[i].pos_b);
		i++;
		top_b = top_b->next;
	}
}

void find_position(t_list **top_a, t_list **top_b)
{
	t_postion *pos;
	int	*tab;
	int i;

	i = 0;
	pos = malloc(sizeof(t_postion) * ft_lstsize(*top_b));
	tab = malloc(sizeof(t_postion) * ft_lstsize(*top_b));
	set_pos_b(*top_b, pos);
	set_pos_a(*top_a, *top_b, pos, tab);
	i = 0;
	printf("\n");
	tab[0]=10;
	while (i < ft_lstsize(*top_b))
	{
		printf("pos: [%i , %i]- %i\n",pos[i].pos_a, pos[i].pos_b,tab[i]);
		i++;
	}
	printf("[]- %i\n",min_of_arr(tab, ft_lstsize(*top_b)));
	aply_sort(pos, min_of_arr(top_a, top_b,tab, ft_lstsize(top_b)));
	free(pos);
}

void aply_sort(t_list **top_a, t_list **top_b, t_postion *pos, int min)
{
	if (pos[min].pos_a >= 0 && pos[min].pos_b >= 0)
	{
		while (pos[min].pos_a && pos[min].pos_b)
		{
			rr(top_a, top_b);
			pos[min].pos_a--;
			pos[min].pos_b--;
		}
		while (pos[min].pos_a)
		{
			rotate(top_a);
			pos[min].pos_a--;
		}
		while (pos[min].pos_b)
		{
			rotate(top_b);
			pos[min].pos_b--;
		}
	}
	if (pos[min].pos_a <= 0 && pos[min].pos_b <= 0)
	{
		
	}
}