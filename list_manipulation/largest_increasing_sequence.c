/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_increasing_sequence.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:46:49 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/19 15:31:01 by obelkhad         ###   ########.fr       */
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

int	*set_list_tab(t_list *top)
{
	t_list	*prev;
	t_list	*next;
	int		*list;
	int		i;
	int		j;

	i = 1;
	next = top->next;
	list = malloc(sizeof(int) * ft_lstsize(top));
	list = ft_memset(list, 1, ft_lstsize(top));
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
	return (list);
}

void	set_head(t_list **head, t_list **node)
{
	ft_lstadd_back(head, ft_lstnew((*node)->content));
	*node = (*node)->next;
}

t_list	*min_on_top(t_list *top)
{
	t_list	*head;
	t_list	*temp;
	t_list	*node;

	head = NULL;
	node = get_min_list(top);
	temp = node;
	if (node == top)
	{
		while (node)
			set_head(&head, &node);
		return (head);
	}
	while (top != node)
	{
		if (temp)
			set_head(&head, &temp);
		else
			set_head(&head, &top);
	}
	return (head);
}

int	*largest_increasing_sequence(t_list *top_a, int *lis)
{
	t_list	*head;
	int		*list;
	int		i;
	int		j;

	head = min_on_top(top_a);
	list = set_list_tab(head);
	i = max_of_arr(list, ft_lstsize(head), ft_lstsize(head) + 1);
	lis = malloc(sizeof(int) * (list[i] + 1));
	lis[0] = list[i];
	j = list[i];
	while (j)
	{
		top_a = get_node_by_value(head, i);
		lis[list[i]] = top_a->content;
		i = max_of_arr(list, i, list[i]);
		j--;
	}
	free_list(&head);
	free(list);
	return (lis);
}
