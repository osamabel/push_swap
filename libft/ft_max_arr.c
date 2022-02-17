/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:53:14 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:09:56 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	max_of_arr(int *list, int size, int last_max)
{
	int	i;
	int	j;
	int	m;

	i = 1;
	j = 0;
	m = list[0];
	while (i < size)
	{
		if (m <= list[i] && list[i] < last_max)
		{
			m = list[i];
			j = i;
		}
		i++;
	}
	return (j);
}
