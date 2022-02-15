/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:19:25 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/15 10:14:36 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void display_node(t_list *top)
{
    if (top)
        printf ("%i ",top->content);
    else
        printf ("\nN U L L\n");
    printf ("\n");
}

int all_done(t_list *top)
{
    while (top->next && top->content < top->next->content)
        top = top->next;
    if (top->next)
        return 0;
    return 1;
}

void display(t_list *top)
{
    if (top)
    {
        while (top)
        {
            printf ("%i ",top->content);
            top = top->next;
        }
    }
    else
        printf ("\nN U L L\n");
    printf ("\n");
}



t_list *get_node_by_value(t_list *top, int position)
{
	int	i;

	i = 0;
	while (top && i < position)
	{
		top = top->next;
		i++;
	}
	if (top)
		return (top);
	return (0);
}



int	max_of_arr(int *list ,int size,int last_max)
{
	int i;
	int j;
	int m;

	i = 1;
	j = 0;
	m = list[0];
	while (i < size)
	{
		if (m <= list[i] && list[i] < last_max)
		{
			m = list[i];
			j = i;
		}
		i++;
	}
	return j;
}

int	min_of_arr(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 1;
	j = 0;
	min = tab[0];
	while (i < size)
	{
		if (min > tab[i])
		{
			min = tab[i];
			j = i;
		}
		i++;
	}
	return j;
}


t_list	*get_max_list(t_list *top)
{
	t_list *head;
	int		max;

	max = top->content;
	head = top;
	top = top->next;
	while (top)
	{
		if (max < top->content)
		{
			max = top->content;
			head = top;
		}
		top = top->next;
	}
	return (head);
}

t_list	*get_min_list(t_list *top)
{
	t_list *head;
	int		min;

	min = top->content;
	head = top;
	top = top->next;
	while (top)
	{
		if (min > top->content)
		{
			min = top->content;
			head = top;
		}
		top = top->next;
	}
	return (head);
}

int	get_pos_by_node(t_list *top, t_list *node)
{
	int	index;

	index = 0;
	while (top != node)
	{
		index++;
		top = top->next;
	}
	return (index);
}
void	free_list(t_list **top)
{
	t_list *node;

	if (top)
	{
		while (*top)
		{
			node = *top;
			*top = (*top)->next;
			free(node);
		}
	}
	*top = NULL;
}