/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_sequence.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:46:49 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/09 15:03:06 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	*ft_memset(int *buf, int c, size_t	len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		buf[i] = c;
		i++;
	}
	return (buf);
}

void	set_list_tab(t_list *top, t_list *next, t_list *prev, int *list)
{
	int i;
	int j;

	i = 1;
	while (next)
	{
		prev = top;
		j = 0;
		while (i != j)
		{
			if (next->content > prev->content && list[i] < list[j] + 1)
				list[i] += 1;
			j++;
			prev = prev->next;
		}
		next = next->next;
		i++;
	}
}

int *largest_increasing_sequence(t_list *top)
{
	t_list *head;
	int	*list;
	int	*list_r;
	int i;
	int j;

	head = top;
	list = malloc(sizeof(int) * ft_lstsize(top));
	list = ft_memset(list, 1,ft_lstsize(top));
	set_list_tab(top, top->next, top ,list);
	i = max_of_arr(list, ft_lstsize(top),ft_lstsize(top));
	list_r = malloc(sizeof(int) * (list[i] + 1));
	list_r[0] = list[i];
	j = list[i];
	while (j)
	{
		head = get_node_by_value(top, i);
		list_r[list[i]] = head->content;
		i = max_of_arr(list, i,list[i]);
		j--;
	}
	free(list);
	return (list_r);
}
