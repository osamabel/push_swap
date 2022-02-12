/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:04:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/12 20:29:52 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void rotate(t_list **top)
{
    t_list *node;
    t_list *temp;

    if (ft_lstsize(*top) > 1)
    {
        node = *top;
        temp = ft_lstlast(*top);
        *top = (*top)->next;
        (*top)->prev = NULL;
        temp->next = node;
        node->next = NULL;
        node->prev = temp;
    }
}

void    rr(t_list **top_a, t_list **top_b)
{
    rotate(top_a);
    rotate(top_b);
}