/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:04:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/08 20:06:43 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void rotate_b(t_list **top_b)
{
    t_list *node;
    t_list *temp;

    if (ft_lstsize(*top_b) > 1)
    {
        node = *top_b;
        temp = ft_lstlast(*top_b, 1, ft_lstsize(*top_b));
        temp->next = *top_b;
        *top_b = (*top_b)->next;
        node->next = NULL;
    }
}