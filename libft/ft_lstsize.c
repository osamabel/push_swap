/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:09:02 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:09:02 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;

	counter = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
