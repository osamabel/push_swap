/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:19:25 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/10 14:33:11 by obelkhad         ###   ########.fr       */
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