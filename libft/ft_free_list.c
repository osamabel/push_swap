/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:48:04 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:04:35 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	free_list(t_list **top)
{
	t_list	*node;

	if (top)
	{
		while (*top)
		{
			node = *top;
			*top = (*top)->next;
			free(node);
		}
	}
	*top = NULL;
}
