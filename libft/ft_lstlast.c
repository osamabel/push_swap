/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:08:29 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:08:29 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	i;

	if (lst)
	{
		i = 0;
		while (lst->next)
		{
			lst = lst->next;
			i++;
		}
		return (lst);
	}
	return (0);
}
