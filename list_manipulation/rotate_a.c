/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:04:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/08 20:06:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void rotate_a(t_list **top_a)
{
    t_list *node;
    t_list *temp;

    if (ft_lstsize(*top_a) > 1)
    {
        node = *top_a;
        temp = ft_lstlast(*top_a, 1, ft_lstsize(*top_a));
        temp->next = *top_a;
        *top_a = (*top_a)->next;
        node->next = NULL;
    }
}