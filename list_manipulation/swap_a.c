/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:01:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/03 23:37:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void swap_a(t_list **top_a)
{
    t_list *node;

    if (ft_lstsize(*top_a) > 1)
    {
        node = *top_a;
        *top_a = (*top_a)->next;
        node->next = (*top_a)->next;
        (*top_a)->next = node;
    }
}