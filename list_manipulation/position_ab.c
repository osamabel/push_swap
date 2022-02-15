/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:31:30 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/14 16:32:34 by obelkhad         ###   ########.fr       */
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
void apply_sort(t_list **top_a, t_list **top_b, t_postion *pos, int min)
{
	while (pos[min].pos_a > 0 && pos[min].pos_b > 0)
	{
		rr(top_a, top_b);  printf("rr\n");
		pos[min].pos_a--;
		pos[min].pos_b--;
	}
	while (pos[min].pos_a < 0 && pos[min].pos_b < 0)
	{
		rrr(top_a, top_b); printf("rrr\n");
		pos[min].pos_a++;
		pos[min].pos_b++;
	}
	while (pos[min].pos_a > 0)
	{
		rotate(top_a);printf("ra\n");
		pos[min].pos_a--;
	}
	while (pos[min].pos_b > 0)
	{
		rotate(top_b);printf("rb\n");
		pos[min].pos_b--;
	}
	while (pos[min].pos_a < 0)
	{
		reverse(top_a);printf("rra\n");
		pos[min].pos_a++;
	}
	while (pos[min].pos_b < 0)
	{
		reverse(top_b);printf("rrb\n");
		pos[min].pos_b++;
	}
	push(top_a, top_b); printf("pa\n");
}

int ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return x;
}

int	max_of_two_number(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int case_1(t_list *top_a, t_list *top_b, t_postion *pos, int *tab)
{
	t_list *node;

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

int case_2(t_list *top_a, t_list *top_b, t_postion *pos, int *tab)
{
	t_list *node;
	int		j;
	int		x;
	int		y;

	node = top_a;
	j = 0;
	while (node->next)
	{
		x = node->content;
		y = node->next->content;
		if (top_b->content > x && y > top_b->content)
		{
			if (j < ft_lstsize(top_a) / 2)
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
			break ;
		}
		j++;
		node = node->next;
	}
	if (node->next)
		return 1;
	return 0;
}

void	case_3(t_list *top_a, t_postion *pos, int *tab)
{
	t_list *node;
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

void	set_pos_a(t_list *top_a, t_list *top_b, t_postion *pos ,int *tab)
{
	pos->index = 0;
	while (top_b)
	{
		if (case_1(top_a, top_b,pos, tab))
		{
			pos->index++;
			top_b = top_b->next;
			continue;
		}
		if (case_2(top_a, top_b,pos, tab))
		{
			pos->index++;
			top_b = top_b->next;
			continue;
		}
		case_3(top_a,pos, tab);
		pos->index++;
		top_b = top_b->next;
	}
}

void find_position(t_list **top_a, t_list **top_b)
{
	t_postion *pos;
	int	*tab;
	int i;

	pos = malloc(sizeof(t_postion) * ft_lstsize(*top_b));
	tab = malloc(sizeof(int) * ft_lstsize(*top_b));
	set_pos_b(*top_b, pos);
	set_pos_a(*top_a, *top_b, pos, tab);
	i = 0;
	// printf("A ->");
	// display(*top_a);
	// printf("B ->");
	// display(*top_b);
	// printf("\n");
	// printf("> min : %i \n",tab[min_of_arr(tab, ft_lstsize(*top_b))]);
	// printf("\n");
	// while (i < ft_lstsize(*top_b))
	// {
	// 	printf("[%i, %i] -> %i\n", pos[i].pos_a, pos[i].pos_b, tab[i]);
	// 	i++;
	// }
	// printf("\n");

	i = min_of_arr(tab, ft_lstsize(*top_b));
	apply_sort(top_a,top_b,pos, i);
	free(pos);
	free(tab);
}
