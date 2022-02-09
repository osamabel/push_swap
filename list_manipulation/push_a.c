/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 22:53:16 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/03 23:37:14 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void push_a(t_list **top_a,t_list **top_b)
{
    t_list *node;

    if (*top_b)
    {
        node = *top_b;
        (*top_b) = (*top_b)->next;
        node->next = *top_a;
        *top_a = node;
    }
}