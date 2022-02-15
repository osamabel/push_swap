/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:01:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/15 11:46:49 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int swap(t_list **top)
{
    int     swap;

    if (ft_lstsize(*top) > 1)
    {
        swap = (*top)->content;
        (*top)->content = (*top)->next->content;
        (*top)->next->content = swap;
    }
    return 1;
}

int    ss(t_list **top_a, t_list **top_b)
{
    swap(top_a);
    swap(top_b);
	write(1, "ss\n", 3);
    return 1;
}

int    sa(t_list **top_a)
{
    swap(top_a);
	write(1, "sa\n", 3);
    return 1;
}

int    sb(t_list **top_b)
{
    swap(top_b);
	write(1, "sb\n", 3);
    return 1;
}