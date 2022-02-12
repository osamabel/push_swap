/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:09:46 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/12 20:27:58 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void reverse(t_list **top)
{
    t_list *temp;

    if (ft_lstsize(*top) > 1)
    {
        temp = ft_lstlast(*top);
        temp->prev->next = NULL;
        temp->prev = NULL;
        temp->next = *top;
        (*top)->prev = temp;
        *top = (*top)->prev;
    }
}

void    rrr(t_list **top_a, t_list **top_b)
{
    reverse(top_a);
    reverse(top_b);
}