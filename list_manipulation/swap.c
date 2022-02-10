/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 23:01:15 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/10 14:26:22 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void swap(t_list **top)
{
    int     swap;

    if (ft_lstsize(*top) > 1)
    {
        swap = (*top)->content;
        (*top)->content = (*top)->next->content;
        (*top)->next->content = swap;
    }
}