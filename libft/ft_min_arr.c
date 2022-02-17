/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelkhad <obelkhad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:53:34 by obelkhad          #+#    #+#             */
/*   Updated: 2022/02/16 17:10:16 by obelkhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_header.h"

int	min_of_arr(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 1;
	j = 0;
	min = tab[0];
	while (i < size)
	{
		if (min > tab[i])
		{
			min = tab[i];
			j = i;
		}
		i++;
	}
	return (j);
}
