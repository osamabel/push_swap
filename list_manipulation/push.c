/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:53:16 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/10 12:17:04 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void push(t_list **top_1,t_list **top_2)
{
    t_list *node;

    if (*top_2)
    {
        node = *top_2;
        *top_2 = (*top_2)->next;
        if (*top_2)
            (*top_2)->prev = NULL;
        node->next = *top_1;
        (*top_1)->prev = node;
        *top_1 = (*top_1)->prev;
    }
}