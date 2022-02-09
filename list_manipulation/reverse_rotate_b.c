/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:09:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/08 20:06:36 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void reverse_b(t_list **top_b)
{
    t_list *node;
    t_list *temp;

    if (ft_lstsize(*top_b) > 1)
    {
        node = *top_b;
        temp = ft_lstlast(*top_b, 1, ft_lstsize(*top_b));
        temp->next = *top_b;
        *top_b = temp;
        while (node->next != *top_b)
            node = node->next;
        node->next = NULL;
    }
}