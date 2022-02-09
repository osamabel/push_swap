/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:01:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/03 23:37:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void swap_b(t_list **top_b)
{
    t_list *node;

    if (ft_lstsize(*top_b) > 1)
    {
        node = *top_b;
        *top_b = (*top_b)->next;
        node->next = (*top_b)->next;
        (*top_b)->next = node;
    }
}