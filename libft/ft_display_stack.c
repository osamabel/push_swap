/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:51:44 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:03:57 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

void	display(t_list *top)
{
	if (top)
	{
		while (top)
		{
			ft_printf ("%i ", top->content);
			top = top->next;
		}
	}
	else
		ft_printf ("N U L L\n");
	ft_printf ("\n");
}
